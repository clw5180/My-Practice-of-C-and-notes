#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

//我的方案：
 int rectCover(int number)
 {
     if (number <= 0)
         return 0;
     int pre = 1, cur = 1;
     while (number--)
     {
         cur = pre + cur;
         pre = cur - pre;
     }
     return pre;
 }

int main()
{
	return 0;
}