#ifndef BASEIO_H
#define BASEIO_H
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <base.h>
int baseputc(int c,FILE*stream)
{
	return putc(c,stream);
}
int basegetc(FILE*stream)
{
	return getc(stream);
}
int baseputchar(int c)
{
	return baseputc(c,stdout);
}
int basegetchar()
{
	return basegetc(stdin);
}
void gotoxy(int x,int y)
{
	COORD pos;
	pos=MkCoord(x,y);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle,pos);
	return;
}
void ChangeColor(WORD color)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle,color);
}
void postcxy(int c,int x,int y,WORD color)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(handle,&csbi);
	SetConsoleCursorPosition(handle,MkCoord(x,y));
	SetConsoleTextAttribute(handle,color);
	baseputchar(c);
	SetConsoleTextAttribute(handle,csbi.wAttributes);
	SetConsoleCursorPosition(handle,csbi.dwCursorPosition);

}
#endif
