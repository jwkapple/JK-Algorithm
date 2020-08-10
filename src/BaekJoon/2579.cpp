#include <iostream>
#include <algorithm>
const int MAX = 301;

int dp[MAX][2];
int data[MAX];

int func(int N, bool both)
{
	if (N == 0 || N == 1) return data[N];

	if (both)
	{
		if (dp[N][1] != 0) return dp[N][1];
		else
		{
			dp[N][1] = std::max(func(N - 1, false), func(N - 2, true)) + data[N];
			return dp[N][1];
		}
	}
	else
	{
		if (dp[N][0] != 0) return dp[N][0];
		else
		{
			dp[N][0] = func(N - 2, true) + data[N];
			return dp[N][0];
		}
	}

}
int main()
{
	int N;


	std::cin >> N;

	data[0] = 0;
	for (int i = 1;i <= N; i++)
	{
		std::cin >> data[i];
	}

	std::cout << func(N, true);
}