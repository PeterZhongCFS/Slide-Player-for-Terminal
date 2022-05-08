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
int scan(FILE*FileHandle,BUFFER*buffer)
{
    (*buffer).clear();
    if(feof(FileHandle))return SCANEOF;
    char in_char;
    while(!feof(FileHandle))
    {
        in_char=fgetc(FileHandle);
        FileX++;
        if(in_char=='\n')
        {
            FileY++;
            FileX=0;
        }
        if(isspace(in_char))continue;
        switch(in_char)
        {
            case '<':
                in_char=fgetc(FileHandle);
                if(in_char!='!')
                {
                    ungetc(in_char,FileHandle);
                    return LPAREN;
                }
                if(fgetc(FileHandle)!='-')
                {
                    Warning("<");
                }
            case '>':return RPAREN;
            case '=':return ASSIGN;
            case '/':return OPCLOSE;
        }
        if(in_char=='\"')
        {
            in_char=fgetc(FileHandle);
            while(in_char!='\"')
            {
                (*buffer).push(in_char);
                in_char=fgetc(FileHandle);
            }
            return ID;
        }
        if(isalnum(in_char))
        {
            while(isalnum(in_char))
            {
               (*buffer).push(in_char);
                in_char=fgetc(FileHandle);
            }
            ungetc(in_char,FileHandle);
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
TAG ReadTag(FILE*FileHandle)
{
    int mode=scan(stdin,&buffer);
    if(mode!=LPAREN)Error("ReadTag:Not")

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
        int mode=scan(stdin,&buffer);
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
