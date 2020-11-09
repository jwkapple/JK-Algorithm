#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e6 + 1;
int N, max = 0;

int dp[MAX];

int main()
{
	Init();

	std::cin >> N;

	int tmp;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> tmp;

		if (!dp[tmp - 1]) dp[tmp] = 1;
		else dp[tmp] = dp[tmp - 1] + 1;

		max = max > dp[tmp] ? max : dp[tmp];
	}

	std::cout << N - max;
}