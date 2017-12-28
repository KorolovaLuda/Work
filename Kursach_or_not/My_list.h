#pragma once
#include<iostream>
#include<set>

using namespace std;

class strange_stack
{	
	
public:
	char* data;
	strange_stack* next;
	strange_stack* pop(char*s,strange_stack*head);
	strange_stack* push(strange_stack*head);
	void previous_push(strange_stack*head);
	strange_stack(char*str);
	//strange_stack();
	void output(strange_stack*head);
	/*char* get_data();
	char* get_previous_data();
	strange_stack* get_head();*/
};
class strange_stack2
{

public:
	set<int> data;
	strange_stack2* next;
	strange_stack2* pop(set<int>s, strange_stack2*head);
	strange_stack2* push(strange_stack2*head);
	void previous_push(strange_stack2*head);
	strange_stack2(set<int>);
	void output(strange_stack2*head);
};