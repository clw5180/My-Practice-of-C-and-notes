#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;



//Insert one char from stringstream
class Solution
{
public:
	//Insert one char from stringstream
	void Insert(char ch)
	{
		str += ch;
		hashMap[ch]++;
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		int len = str.size();
		for (int i = 0; i < len; ++i)
		{
			if (hashMap[str[i]] == 1)
				return str[i];
		}
		return '#';
	}
private:
	string str;
	map<char, int> hashMap;
};

int main()
{
	
	return 0;
}