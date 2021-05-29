#include<bits/stdc++.h>
using namespace std;
vector<int>vt = {3, 1, 4, 2, 5};
struct Cmp {
	bool operator()(int i, int j)
	{
		return vt[i] < vt[j];
	}
};

void SamplePriorityQueueWithLamda()
{
	// using lambda to compare elements.

	vector<vector<int>>& nums;
	vector<int>next(n, 0);
	auto compare = [&nums, &next](int i, int j)
	{
		return nums[i][next[i]] > nums[j][next[j]];
	};
	priority_queue<int, vector<int>, decltype(compare)> q(compare);



	auto compare = [](int lhs, int rhs)
	{
		return lhs % 2 < rhs % 2;
	};

	std::priority_queue<int, std::vector<int>, decltype(compare)> q(compare);

	for (int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
		q.push(n);

	while (!q.empty())
	{
		cout << q.top() << "\n";
		q.pop();
	}
}


int main ()
{
	priority_queue <int, vector<int>, Cmp> g;
	g.push(0);
	g.push(1);
	g.push(2);
	g.push(3);
	g.push(4);

	while (!g.empty())
	{
		cout << g.top() << "\n";
		g.pop();
	}
	SamplePriorityQueueWithLamda();
	cout << '\n';
	return 0;
}
