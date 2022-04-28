#ifndef BASE_H
#define BASE_H
#include <windows.h>
COORD MkCoord(int x,int y)
{
	COORD ret;
	ret.X=x,ret.Y=y;
	return ret;
}
#endif
