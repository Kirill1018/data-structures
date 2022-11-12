#include "check.h"

Check::Check()
{
	exp = NULL;
	_size = 0;//размер массива
}

Check::Check(const char* _exp)
{
	_size = strlen(_exp);
	exp = new char[_size++];
	strcpy(exp, _exp);
}

Check::~Check()
{
	//exp = '\0';
	delete[]exp;
	exp = NULL;
}

bool Check::Test()
{
	stack <char> st1;
	bool isExpCor = true;
	while (*exp)
	{
		if (*exp == '(') st1.push(*exp);
		if (*exp == ')')
		{
			if (st1.empty())
			{
				isExpCor = false;
				break;
			}
			else
			{
				//char bracket;
				st1.pop();
			}
		}
		exp++;
	}
	return false;
}