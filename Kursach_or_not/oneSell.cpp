#include "oneSell.h"

bool oneSell::num_check(char*str)
{
	int len = strlen(str);
	if (str[0] == '.' || str[0] == '-')
		return false;
	int count = 0;
	for (int i = 1; i < len; i++)
	{
		if (str[i] == '.')
			count++;
		if (str[i] == '-')
			return false;
	}
	if (count > 1)
		return false;
	return true;
}

bool oneSell::empty_check(char*str)
{
	if (strcmp(str, "") == 0)
		return false;
	else
		return true;
}

oneSell::oneSell() {
	tab = nullptr;
	n = 0;
}

/*oneSell::~oneSell() {
	delete[] tab;
}*/