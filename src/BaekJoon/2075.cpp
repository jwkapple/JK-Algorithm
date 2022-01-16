#include <iostream>
#include <vector>
#include <queue>

#define pii std::pair<int,int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 1500 + 1;

std::priority_queue<pii> Q;
int data[MAX][MAX], dp[MAX];
int N;

int main()
{
	Init();

	std::cin >> N;

	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= N; ++x)
		{
			std::cin >> data[y][x];
		}
		dp[y] = N;
	}

	for (int i = 1; i <= N; ++i)
	{
		Q.push(pii(data[N][i], i));
	}

	int cur = 0;
	while (true)
	{
		auto [v, x] = Q.top();
		Q.pop();

		if (++cur == N)
		{
			std::cout << v;
			return 0;
		}

		if (dp[x] == 1)	continue;

		dp[x]--;

		Q.push(pii(data[dp[x]][x], x));
	}
}