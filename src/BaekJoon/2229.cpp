#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1000 + 1;

int data[MAX], DP[MAX], GDP[MAX][MAX];
int N;

int gap(int from, int to)
{
	if (from == to) return 0;

	auto& ret = GDP[from][to];
	if (ret) return ret;

	int min = 1e9, max = 0;

	for (int i = from; i <= to; ++i)
	{
		min = min > data[i] ? data[i] : min;
		max = max > data[i] ? max : data[i];
	}

	return ret = max - min;
}
int func(int from)
{
	if (from == N) return 0;
	auto& ret = DP[from];
	if (ret) return ret;

	int cur;
	for (int i = 1; from + i <= N; ++i)
	{
		cur = func(from + i) + gap(from, from + i - 1);
		ret = ret > cur ? ret : cur;
	}

	return ret;
}

int main()
{
	Init();

	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> data[i];
	}

	std::cout << func(0);
}