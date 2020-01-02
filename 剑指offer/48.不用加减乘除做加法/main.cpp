#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Add(int num1, int num2)
{
	int s = num1 ^ num2;
	int c = (num1 & num2) << 1;
	int result;
	if (c != 0)
		result = Add(s, c);
	else
		result = s;
	return result;	
}

int main()
{
	cout << Add(111, 899) << endl;
	return 0;
}