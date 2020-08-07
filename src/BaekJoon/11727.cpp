#include <iostream>
#include <algorithm>

const int MAX = 1001;
int dp[MAX];

int func(int num)
{
	if (num == 1) return 1;
	if (num == 2) return 3;
	if (dp[num] != -1) return dp[num] % 10007;

	dp[num] = (func(num - 1) + func(num - 2) * 2) % 10007;

	return dp[num];
}
int main()
{
	int N;
	std::cin >> N;

	std::fill(dp, dp + MAX, -1);

	std::cout << func(N);
}

