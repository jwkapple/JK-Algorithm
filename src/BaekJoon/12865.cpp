#include <iostream>
#include <vector>
#include <algorithm>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

std::vector<pii> jewery;
int dp[101][100000 + 1];

int N, K, result = 0;

int func(int J, int W)
{
	if (jewery[J].first > W) return dp[J - 1][W];
	else
	{
		return std::max(jewery[J].second + dp[J - 1][W - jewery[J].first], dp[J - 1][W]);
	}
}
int main()
{
	Init();

	std::cin >> N >> K;

	uint32_t w, v;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> w >> v;

		jewery.push_back(std::make_pair(w, v));
	}

	jewery.push_back(std::make_pair(0, 0));
	std::sort(jewery.begin(), jewery.end());

	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= K; ++x)
		{
			dp[y][x] = func(y, x);
		}
	}

	std::cout << dp[N][K];
}