#pragma once
#include"Global_vars.h"
#include"Input_output.h"
#include"Pie_chart.h"
extern char* buff;
extern int input_mode;
extern float param1, param2;
extern float white[3];
extern float black[3];
extern int str;
extern bool printable;
extern int diag_mode;
extern bool build;
extern bool confirm,start;
extern pie obj;

void drawmenu();
void renderScene(void);
void drow_button1();
void drow_button2();
void drow_button3();
