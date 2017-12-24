#include"Global_vars.h"
char* buff = new char[100];
int input_mode = 0;
int diag_mode = 0;
float param1 = 900, param2 = 500;
float white[3] = { 1, 1, 1 };
float black[3] = { 0, 0, 0 };
int str = 0;
bool printable = false;
bool confirm = false, build = true;
int index[2];
char*** table=nullptr;
void allocate_table()
{
	table = new char**[11];
	for (int i = 0; i < 11; i++)
		table[i] = new char*[3];
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 3; j++)
			table[i][j] = new char[10];
}
void clear_table()
{
	cout << "clear" << endl;
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 3; j++)
			strcpy(table[i][j], "");
}