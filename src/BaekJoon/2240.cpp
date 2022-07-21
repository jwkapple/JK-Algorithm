#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 1000 + 1;

int data[MAX], DP[MAX][31];
int T, W;

int func(int time, int move)
{
	if (time > T || move > W)
		return 0;

	auto &ret = DP[time][move];

	if (ret)
		return ret;

	if (move % 2 && data[time] == 2)
		ret++; // 2에 위치
	if (!(move % 2) && data[time] == 1)
		ret++;

	int left = func(time + 1, move);
	int right = func(time + 1, move + 1);

	return ret += left > right ? left : right;
}

int main()
{
	Init();

	std::cin >> T >> W;

	for (int i = 1; i <= T; ++i)
	{
		std::cin >> data[i];
	}

	std::cout << func(0, 0);
}