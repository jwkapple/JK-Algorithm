#include <iostream>

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 500 + 1;

int data[MAX];
int dp[MAX];
int N, cur = 0;

int func(int from, int to, int num)
{
	if (from == to) return from;
	if (from + 1 == to)
	{
		if (dp[from] > num) return from;
		else return to;
	}

	int mid = (from + to) / 2;

	if (dp[mid] >= num) return func(from, mid, num);
	else return func(mid + 1, to, num);
}
int main()
{
	Init();

	dp[0] = -1;
	std::cin >> N;

	int from, to;
	for (int i = 0; i < N; ++i) { std::cin >> from >> to; data[from] = to; }

	for (int i = 1; i < MAX; ++i)
	{
		auto d = data[i];
		if (!d) continue;
		if (d > dp[cur]) dp[++cur] = d;
		else dp[func(0, cur, d)] = d;
	}

	std::cout << N - cur;
}