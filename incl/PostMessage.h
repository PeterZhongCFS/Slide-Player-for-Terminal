#ifndef POSTMSG_H
#define POSTMSG_H
#include <stdio.h>
#include <ctype.h>
#include <windows.h>
int Xto10(char x)
{
    return x-(isdigit(x)?'0':(isupper(x)?'A':'a')-10);
}
void Error(const char*file,int X,int Y,const char*str)
{
    
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE OutputHandle;
    OutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(OutputHandle,&csbi);
    csbi.wAttributes=(csbi.wAttributes&0xf0)|0x07;
    SetConsoleTextAttribute(OutputHandle,csbi.wAttributes);
    printf("%s",file);
    printf(":");
    if(Y!=0)
    {
        printf("%d:%d:",Y,X);
    }
    while(*str)
    {
        if(*str!='$')
        {
            putchar(*str);
            str++;
            continue;
        }
        str++;
        if(*str==';')
        {
            putchar('$');
            str++;
            continue;
        }
        if(*str!='-')
            csbi.wAttributes=(csbi.wAttributes&0x0f)|(Xto10(*str)<<4);
        str++;
        if(*str!='-')
            csbi.wAttributes=(csbi.wAttributes&0xf0)|Xto10(*str);
        SetConsoleTextAttribute(OutputHandle,csbi.wAttributes);
        str++;
    }
    exit(0);
}
void PostMsg(int X,int Y,const char*str)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE OutputHandle;
    OutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(OutputHandle,&csbi);
    csbi.wAttributes=(csbi.wAttributes&0xf0)|0x07;
    SetConsoleTextAttribute(OutputHandle,csbi.wAttributes);
    if(Y!=0)
    {
        printf("%d:%d:",Y,X);
    }
    while(*str)
    {
        if(*str!='$')
        {
            putchar(*str);
            str++;
            continue;
        }
        str++;
        if(*str==';')
        {
            putchar('$');
            str++;
            continue;
        }
        if(*str!='-')
            csbi.wAttributes=(csbi.wAttributes&0x0f)|(Xto10(*str)<<4);
        str++;
        if(*str!='-')
            csbi.wAttributes=(csbi.wAttributes&0xf0)|Xto10(*str);
        SetConsoleTextAttribute(OutputHandle,csbi.wAttributes);
        str++;
    }
}
void Warning(int X,int Y,const char*str)
{
    
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE OutputHandle;
    OutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(OutputHandle,&csbi);
    csbi.wAttributes=(csbi.wAttributes&0xf0)|0x06;
    SetConsoleTextAttribute(OutputHandle,csbi.wAttributes);
    printf("Warning");
    csbi.wAttributes=(csbi.wAttributes&0xf0)|0x07;
    SetConsoleTextAttribute(OutputHandle,csbi.wAttributes);
    printf(":");
    if(Y!=0)
    {
        printf("%d:%d:",Y,X);
    }
    while(*str)
    {
        if(*str!='$')
        {
            putchar(*str);
            str++;
            continue;
        }
        str++;
        if(*str==';')
        {
            putchar('$');
            str++;
            continue;
        }
        if(*str!='-')
            csbi.wAttributes=(csbi.wAttributes&0x0f)|(Xto10(*str)<<4);
        str++;
        if(*str!='-')
            csbi.wAttributes=(csbi.wAttributes&0xf0)|Xto10(*str);
        SetConsoleTextAttribute(OutputHandle,csbi.wAttributes);
        str++;
    }
}
#endif
