#include"My_list.h"


strange_stack* strange_stack::pop(char*s,strange_stack*head)
{
	strange_stack* new_head = new strange_stack(s);
	new_head->next = head;
	return new_head;
}
strange_stack* strange_stack::push(strange_stack*head)
{
	strange_stack* temp = head;
	strange_stack*res = NULL;
	if (head != NULL)
	{
		res = temp->next;
		delete[] temp->data;
		delete temp;
	}
	return res;
}
void strange_stack::previous_push(strange_stack*head)
{
	if (head != NULL)
	{
		strange_stack* temp = head, *del = head->next;
		if (head->next != NULL)
		{
			temp->next = temp->next->next;
			delete[] del->data;
			delete del;
		}
	}
}

strange_stack::strange_stack(char*str)
{
	data = new char[100];
	strcpy(data, str);
	next = NULL;
}


void strange_stack::output(strange_stack*head)
{
	if (head == NULL)
		cout << "Empty" << endl;
	else
	{
		strange_stack* k;
		k = head;
		while (k != NULL)
		{
			cout << k->data << endl;
			k = k->next;
		}
		cout << endl;
	}
}








strange_stack2* strange_stack2::pop(set<int> s, strange_stack2*head)
{
	strange_stack2* new_head = new strange_stack2(s);
	new_head->next = head;
	return new_head;
}
strange_stack2* strange_stack2::push(strange_stack2*head)
{
	strange_stack2* temp = head;
	strange_stack2*res = NULL;
	if (head != NULL)
	{
		res = temp->next;
	}
	return res;
}
void strange_stack2::previous_push(strange_stack2*head)
{
	if (head != NULL)
	{
		strange_stack2* temp = head, *del = head->next;
		if (head->next != NULL)
		{
			temp->next = temp->next->next;
			delete del;
		}
	}
}

strange_stack2::strange_stack2(set<int> s)
{
	data = s;
	next = NULL;
}


void strange_stack2::output(strange_stack2*head)
{
	if (head == NULL)
		cout << "Empty" << endl;
	else
	{
		strange_stack2* k;
		k = head;
		while (k != NULL)
		{
			k = k->next;
		}
		cout << endl;
	}
}