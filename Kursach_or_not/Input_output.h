#pragma once
#include"Global_vars.h"
#include"VennDiagram.h"

extern char* buff;
extern int input_mode;
extern float param1, param2;
extern float white[3];
extern float black[3];
extern int str;
extern bool printable;
extern int diag_mode;
extern bool build;
extern bool confirm;
extern char*** table;

void DrawText(const char *text, int length, int x, int y,float* color);
void Drawinput1();
void Drawinput2(int n);
void Drawinput3(int n);
void Drawinput4(int n);
void Draw_num();
void Draw_table2();
void Draw_table3();
void Draw_table4();