#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
class Check
{
	char* exp;
	int _size;
public:
	Check();
	Check(const char* _exp);
	~Check();
	bool Test();
};

