#include <iostream>
#include <limits.h>

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e3 + 1;

int N;
int data[MAX];
int min = INT_MAX;
int result = 0;

std::pair<int, int> dp[MAX]; // <left, right>

int buf(int num)
{
	if (dp[num].second != -1) return dp[num].second;

	if (data[num] == min || num == N - 1)
	{
		dp[num].second = 0;
		return dp[num].second;
	}

	int Max = -1;

	for (int i = num; i < N; i++)
	{
		if (data[i] < data[num])
		{
			if (Max < buf(i)) Max = dp[i].second;
		}
	}

	if (Max == -1) dp[num].second = 0;
	else dp[num].second = Max + 1;

	return dp[num].second;
}

int debuf(int num)
{
	if (dp[num].first != -1) return dp[num].first;

	if (data[num] == min || num == 0)
	{
		dp[num].first = 0;
		return dp[num].first;
	}

	int Max = -1;

	for (int i = num; i >= 0; --i)
	{
		if (data[i] < data[num])
		{
			if (Max < debuf(i)) Max = dp[i].first;
		}
	}

	if (Max == -1) dp[num].first = 0;
	else dp[num].first = Max + 1;

	return dp[num].first;
}
int main()
{
	Init();

	std::cin >> N;

	for (int i = 0;i < N; i++)
	{
		dp[i].first = -1;
		dp[i].second = -1;
	}
	int tmp;

	for (int i = 0; i < N; i++)
	{
		std::cin >> tmp;
		if (tmp < min) min = tmp;
		data[i] = tmp;
	}

	for (int i = 0; i < N;i++)
	{
		buf(i);
		debuf(N - i - 1);
	}

	int max = 0;
	for (int i = 0;i < N; i++)
	{
		int total = dp[i].first + dp[i].second;
		if (total > max) max = total;
	}
	std::cout << max + 1;
}