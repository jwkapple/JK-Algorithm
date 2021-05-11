#include <iostream>
#include <algorithm>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

int N, M, mx, dp[1001][1001];

int main()
{
	Init();
	std::cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			int t;
			std::cin >> t;
			if (t) continue;
			dp[i][j] = std::min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }) + 1;
			mx = std::max(mx, dp[i][j]);
		}
	}
	std::cout << mx << "\n";
}