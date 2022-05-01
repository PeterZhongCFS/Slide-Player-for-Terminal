#ifndef RESOURCE_H
#define RESOURCE_H
typedef struct{
    unsigned size;
    char*text;
    WORD*colors;
}TEXTBOX;
typedef struct{
    unsigned height;
    unsigned width;
    WORD**colors;
}IMAGE
#endif
