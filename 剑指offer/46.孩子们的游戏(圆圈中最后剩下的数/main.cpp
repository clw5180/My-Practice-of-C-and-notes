#include <iostream>
#include <string>
#include <vector>

using namespace std;

//看剑指offer答案
//约瑟夫环问题
int LastRemaining_Solution(int n, int m)
{
	if (n <= 0 || m <= 0)
		return -1;
	
	int last = 0;
	for (int i = 2; i <= n; ++i)
	{
		last = (last + m) % i;
	}
	return last;
}

int main()
{
    
	return 0;
}