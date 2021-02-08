#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 30 + 1;

int dp[MAX];
int N;

int main()
{
	Init();

	std::cin >> N;

	dp[0] = 1, dp[2] = 3;

	for (int i = 4; i <= N; ++i)
	{
		if (!(i % 2))
		{
			dp[i] = 3 * dp[i - 2];

			for (int j = i - 4; j >= 0; j -= 2)
			{
				dp[i] += 2 * dp[j];
			}
		}
	}

	std::cout << dp[N];
}