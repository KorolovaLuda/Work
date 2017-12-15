#pragma once
#include<iostream>
#include<Windows.h>
#include<GL\glew.h>
#include<GL\freeglut.h>
#include"Global_vars.h"
#include"VennDiagram.h"

using namespace std;

extern char* buff;
extern int input_mode;
extern float param1, param2;
extern float white[3];
extern float black[3];

void input1(unsigned char key, int x, int y);
void DrawText(const char *text, int length, int x, int y,float* color);
void Drawinput1();