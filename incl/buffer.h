#ifndef BUFFER_H
#define BUFFER_H
#include <stdlib.h>
#include <string.h>
class BUFFER
{
private:
    int buffer_size;
    int buffer_tot;
    char*buffer_memory;
    void moremem()
    {
        buffer_size<<=1;
        char*buffer_temp=buffer_memory;
        buffer_memory=(char*)malloc(buffer_size);
        memset(buffer_memory,0x00,buffer_size);
        memcpy(buffer_memory,buffer_temp,buffer_size>>1);
    }
public:
    void clear()
    {
        if(buffer_memory!=NULL)free(buffer_memory);
        buffer_size=32;
        buffer_tot=0;
        buffer_memory=(char*)malloc(buffer_size);
        memset(buffer_memory,0x00,buffer_size);
    }
    void push(int in_char)
    {
        if(buffer_tot==buffer_size)moremem();
        *(buffer_memory+buffer_tot)=in_char;
        buffer_tot++;
    }
    const char*reading()
    {
        return buffer_memory;
    }
    BUFFER()
    {
        buffer_memory=NULL;
        clear();
    }
    ~BUFFER()
    {
        free(buffer_memory);
    }
};
#endif
