#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <cstring>
#include <stdio.h>
#include <fstream>

using namespace std;


struct linked_list
{
	char* key;                            //if we save number, all definitions in list will have same number, so we will not found the word, wich we need
	char*def;
	linked_list *Next;
}*head;

struct dictionary
{
	linked_list* head;
	linked_list* tail;
}*mas;

struct tabl
{
	char leter;
	int num;
};

long int hash_function(char* key, int size);
int file_output(dictionary**, int);
void linkedlist_words(char *key, int index);
bool check_symbols(char*S);
dictionary** rebuild(dictionary**Dict, int old_size);
void search(dictionary**Dict, char*key, int size);
linked_list* create_list(linked_list* head, char*word, char* tran);
linked_list* add(linked_list* tail, char*word, char* tran);
linked_list* del(linked_list* head);
bool test(dictionary** dict, int size);