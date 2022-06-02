#ifndef ST1SCAN_H
#define ST1SCAN_H
#include <stdio.h>
#include <ctype.h>
#include <token.h>
#include <buffer.h>
#include <PostMessage.h>
enum OPCLS{OPEN,CLOSE,OP};
typedef struct{
    OPCLS opcls;
    char title[16];
    char subtitle[16][16];
    char subcontent[16][64];
}TAG;
void RaadST1(const char*);
int FileX=0,FileY=1;
char stdget(FILE*fp)
{
    char in_char=fgetc(fp);
    if(in_char=='\n')
        FileX=0,FileY++;
    else if(!feof(fp))
        FileX++;
    return in_char;
}
void stdunget(char c,File*fp)
{
    ungetc(c,fp);
    FileX--;
    return;
}
int scan(const char*fn,FILE*FileHandle,BUFFER*buffer)
{
    kel:
    (*buffer).clear();
    if(feof(FileHandle))return SCANEOF;
    int cnt;
    char in_char;
    while(!feof(FileHandle))
    {
        in_char=stdget(FileHandle);
        if(isspace(in_char))continue;
        switch(in_char)
        {
            case '<':
                in_char=stdget(FileHandle);
                if(in_char!='!')
                {
                    stdunget(in_char,FileHandle);
                    return LPAREN;
                }
                if((in_char=stdget(FileHandle))!='-')
                {
                    stdunget(in_char,FileHandle);
                    Error(fn,FileX,FileY,"Comment formatting error.We use Comment as $-2<!-- (Comment Content) -->$-7");
                }
                if((in_char=stdget(FileHandle))!='-')
                {
                    stdunget(in_char,FileHandle);
                    Error(fn,FileX,FileY,"Comment formatting error.We use Comment as $-2<!-- (Comment Content) -->$-7");
                }
                cnt=0;
                while(1)
                {
                    in_char=stdget(FileHandle);
                    if(feof(FileHandle))
                    {
                        Error(fn,FileX+1,FileY,"Comment has no end");
                    }   
                    FileX++;
                    if(in_char=='>')
                    {
                        if(cnt>2)
                            goto kel;
                    }
                    if(in_char=='-')cnt++;
                    else    cnt=0;
                }

                break;
            case '>':return RPAREN;
            case '=':return ASSIGN;
            case '/':return OPCLOSE;
        }
        if(in_char=='\"')
        {
            in_char=stdget(FileHandle);
            while(in_char!='\"')
            {
                (*buffer).push(in_char);
                in_char=stdget(FileHandle);
            }
            return ID;
        }
        if(isalnum(in_char))
        {
            while(isalnum(in_char))
            {
               (*buffer).push(in_char);
                in_char=stdget(FileHandle);
            }
            stdunget(in_char,FileHandle);
            return ID;
        }
        if(feof(FileHandle))return SCANEOF;
        (*buffer).push(in_char);
        return UDF;
    }
    return SCANEOF;
}
void Content()
{

}
TAG ReadTag(const char*file,FILE*FileHandle)
{
    BUFFER buffer;
    int mode=scan(file,stdin,&buffer);
    if(mode!=LPAREN)Error(file,FileX,FileY,"ReadTag:Not");

}
void ReadST1(const char*file)
{
    FILE*FileHandle=fopen(file,"r");
    if(FileHandle==0){
        puts("No this file.");
        exit(0);
    }
    BUFFER buffer;
    while(1)
    {
        int mode=scan(file,stdin,&buffer);
        printf("-------------\n");
        if(mode==-1)printf("%d",*buffer.reading());
        printf("%d{%s}\n",mode,buffer.reading());
        if(mode==SCANEOF)break;
    }
    fclose(FileHandle);
}
/*s
<!-- Simple -->
<Slide>
<Page>
<TextBox>
Hello,World!
</TextBox>
<Image height=2 width=3>
f0 0f f0
0f f0 0f
</Image>
</Page>
<Page>
<TextBox>
End
</TextBox>
</Slide>
*/
#endif
