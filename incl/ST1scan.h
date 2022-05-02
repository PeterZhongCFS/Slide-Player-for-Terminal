#ifndef ST1SCAN_H
#define ST1SCAN_H
#include <stdio.h>
#include <ctype.h>
#include <token.h>
void RaadST1(const char*);
void scan(FILE*FileHandle)
{
    if(feof(FileHandle))return SCANEOF;
    char in_char;
    while(!feof(FileHandle))
    {
        in_char=fgetc(FileHandle);
        if(isspace(in_char))continue;
        switch(in_char)
        {
            case '(':return LPAREN;
            case ')':return RPAREN;
        }
    }
    return SCANEOF;
}
void ReadST1(const char*file)
{
    FILE*FileHandle=fopen(file,"r");
    
}
/*
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
