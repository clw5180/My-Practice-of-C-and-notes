#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

//�ҵķ�����
class Solution {
public:
	void Insert(int num)
	{
		m_vec.push_back(num);
	}

	double GetMedian()
	{
		sort(m_vec.begin(), m_vec.end());
		int len = m_vec.size();
		return len % 2 == 0 ? (m_vec[len / 2] + m_vec[len / 2 - 1]) / 2.0 : m_vec[(len - 1) / 2];
	}

private:
	vector<int> m_vec;
};


//���ѷ�����https://www.nowcoder.com/questionTerminal/9be0172896bd43948f8a32fb954e1be1
class Solution {
	// �ұ�С���ѵ�Ԫ�ض�������ߴ󶥶ѵ�Ԫ�أ��������Ԫ�صĸ�����Ҫô���ұ���ȣ�ż�������룩��Ҫô���ұߴ�1�����������룩
	// �󶥶�
	priority_queue<int, vector<int>, less<int> > p;
	// С����
	priority_queue<int, vector<int>, greater<int> > q;

public:
	void Insert(int num) {
		if (p.empty() || num <= p.top()) p.push(num);
		else q.push(num);

		// ��ߴ󶥶ѵĴ�С�����Ա��ұ�С���Ѵ�1�����������룩
		if (p.size() == q.size() + 2) q.push(p.top()), p.pop();

		// ��Ϊ��󷵻ص�ֻ�п�������ߴ󶥶ѵĶѶ��������ұ�С���ѵĴ�С���ܱ����С���Ѵ�
		if (p.size() + 1 == q.size()) p.push(q.top()), q.pop();
	}
	double GetMedian() {
		return p.size() == q.size() ? (p.top() + q.top()) / 2.0 : p.top();
	}
};

//���Ѻ���С�ѵĵײ�ʵ��
class Solution {
private:
	vector<int> max_heap;
	vector<int> min_heap;

	void adjust_heap(vector<int> &nums, int lo, int hi, bool is_max) {
		for (int cur = lo, next = cur * 2 + 1; next <= hi; cur = next, next = cur * 2 + 1) {
			if (is_max) {
				if (next < hi && nums[next + 1] > nums[next]) {
					++next;
				}
				if (nums[next] > nums[cur]) {
					swap(nums[next], nums[cur]);
				}
				else {
					break;
				}
			}
			else {
				if (next < hi && nums[next + 1] < nums[next]) {
					++next;
				}
				if (nums[next] < nums[cur]) {
					swap(nums[next], nums[cur]);
				}
				else {
					break;
				}
			}
		}
	}

	void build_heap(vector<int> &heap, bool is_max) {
		int n = heap.size();
		for (int i = n / 2 - 1; i >= 0; --i) {
			adjust_heap(heap, i, n - 1, is_max);
		}
	}

	int pop(vector<int> &heap, bool is_max) {
		int ret = heap[0];
		heap.erase(heap.begin());
		build_heap(heap, is_max);
		return ret;
	}

	void push(vector<int> &heap, int num, bool is_max) {
		heap.emplace_back(num);
		build_heap(heap, is_max);
	}

public:
	void Insert(int num) {
		if (min_heap.empty() || num > min_heap[0]) {
			push(min_heap, num, false);
		}
		else {
			push(max_heap, num, true);
		}

		if (min_heap.size() == max_heap.size() + 2) {
			push(max_heap, pop(min_heap, false), true);
		}

		if (min_heap.size() + 1 == max_heap.size()) {
			push(min_heap, pop(max_heap, true), false);
		}
	}

	double GetMedian() {
		return min_heap.size() == max_heap.si***_heap[0] + max_heap[0]) / 2. : min_heap[0];
	}

};

int main()
{
}