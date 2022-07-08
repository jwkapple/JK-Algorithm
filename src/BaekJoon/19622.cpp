#include <iostream>
#include <algorithm>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

struct Node
{
	int From;
	int To;
	int Value;

	Node(){};
	Node(int f, int t, int v) : From(f), To(t), Value(v){};
};

bool operator<(const Node &L, const Node &R)
{
	if (L.From == R.From)
	{
		return L.Value < R.Value;
	}

	else
		return L.From < R.From;
}

const int MAX = 1e5 + 1;

std::vector<Node> data;
int DP[MAX];
int N;

int func(int time, int cur)
{
	if (cur == N)
		return 0;

	auto &current = data[cur];
	if (time > data[cur].From)
	{
		return func(time, cur + 1);
	}

	auto &dp = DP[cur];
	if (dp)
		return dp;

	int on = func(current.To, cur + 1) + current.Value;
	int off = func(time, cur + 1);

	return dp = on > off ? on : off;
}
int main()
{
	Init();

	std::cin >> N;

	int from, to, value;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> from >> to >> value;

		data.push_back(Node(from, to, value));
	}

	std::sort(data.begin(), data.end());

	std::cout << func(0, 0);
}