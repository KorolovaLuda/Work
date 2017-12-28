#include"Global_vars.h"
char* buff = new char[100];
int input_mode = 0;
int diag_mode = 0;
float param1 = 900, param2 = 500;
float white[3] = { 1, 1, 1 };
float black[3] = { 0, 0, 0 };
float colors[11][3] =  {0.05, 0.08, 0.88,
						0.30, 0.16, 0.80,
						0.05, 0.24, 0.72,
						0.30, 0.32, 0.64,
						0.05, 0.40, 0.56,
						0.30, 0.48, 0.48,
						0.05, 0.56, 0.40,
						0.30, 0.64, 0.32,
						0.05, 0.72, 0.24,
						0.30, 0.80, 0.16,
						0.05, 0.88, 0.08
						};
int str = 0;
bool printable = false;
bool confirm = false, build = false, start = false;
int index[2];
char*** table=nullptr;
float pi = 3.14159265359;
void allocate_table()
{
	table = new char**[11];
	for (int i = 0; i < 11; i++)
		table[i] = new char*[4];
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 4; j++)
			table[i][j] = new char[10];
}
void clear_table()
{
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 4; j++)
			strcpy(table[i][j], "");
}