#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

/*
1、思路  详见https://cuijiahua.com/blog/2018/02/basis_64.html
我们可以使用一个双端队列deque。

我们可以用STL中的deque来实现，接下来我们以数组{2,3,4,2,6,2,5,1}为例，来细说整体思路。

数组的第一个数字是2，把它存入队列中。第二个数字是3，比2大，所以2不可能是滑动窗口中的最大值，因此把2从队列里删除，再把3存入队列中。第三个数字是4，比3大，同样的删3存4。此时滑动窗口中已经有3个数字，而它的最大值4位于队列的头部。

第四个数字2比4小，但是当4滑出之后它还是有可能成为最大值的，所以我们把2存入队列的尾部。下一个数字是6，比4和2都大，删4和2，存6。就这样依次进行，最大值永远位于队列的头部。

但是我们怎样判断滑动窗口是否包括一个数字？应该在队列里存入数字在数组里的下标，而不是数值。当一个数字的下标与当前处理的数字的下标之差大于或者相等于滑动窗口大小时，这个数字已经从窗口中滑出，可以从队列中删除。


*/
//例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 
vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
	if (num.size() < size || size == 0)
		return {};

	deque<int> deqIndex;  //clw note：根据后面的逻辑，最大容量也就是3，比如6,5,4,2,1,1

	//先用前size-1个数把deque建立起来，后面"访问第size个数然后写max"就可以循环进行了。这个时候滑动窗还没建立
	for (unsigned int i = 0; i < size - 1; i++) 
	{
		// 如果deqIndex非空，并且新的数字大于等于队列中最小的数字，则删除队列中最小的数字
		// 否则保留，因为虽然新的数字比队列里的小，但是可能滑动窗滑到后面就成最大值了，比如6,5,4,2,1,1
		while (!deqIndex.empty() && num[i] >= num[deqIndex.back()]) 
		{
			deqIndex.pop_back();
		}
		deqIndex.push_back(i);  //
	}

	vector<int> maxInWindows;
	for (unsigned int i = size - 1; i < num.size(); i++)  //从i=3开始
	{
		//如果要进来的数比队列尾部的最小值大，则弹出尾部的值
		while (!deqIndex.empty() && num[i] >= num[deqIndex.back()])
		{
			deqIndex.pop_back();
		}

		//如果i已经走远，比如i=6，size=3，那么窗口中只有6,5,4，此时index=3对应的值已经不起作用，应该移出队列
		if (!deqIndex.empty() && deqIndex.front() <= int(i - size))

		{
			deqIndex.pop_front();
		}

		//两种情况：
		//最大值进队尾，其实也是队头，如之前队列里是5，4，要进来6；5和4在经过上面代码会弹出，因此队列只有6一个数。
		//不是最大值，进队尾。如之前队列里是5，3进来到队尾，取的是位于队头的最大值5。
		deqIndex.push_back(i);

		//取队头最大值
		maxInWindows.push_back(num[deqIndex.front()]);
	}

	return maxInWindows;
}

int main()
{
	//vector<int> vec = maxInWindows({ 2, 3, 4, 2, 6, 2, 5, 1 }, 3);
	vector<int> vec = maxInWindows({ 2, 3, 4, 2, 6, 2, 5, 1 }, 3);
	//vector<int> vec = maxInWindows({ -2, -3, -4, -2, -6, -2, -5, -1 }, 3);
	for (const auto &n : vec)
		cout << n << endl;
	return 0;
}