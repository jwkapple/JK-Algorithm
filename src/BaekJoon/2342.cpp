#include <iostream>
#include <algorithm>
#include <cstdlib>

#define ZERO 2

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e5 + 2;

int adjcent[5][5] =
{
	2, 2, 2, 2, 2,
	0, 1, 3, 4, 3,
	0, 3, 1, 3, 4,
	0, 4, 3, 1, 3,
	0, 3, 4, 3, 1
};
int dp[MAX][5][5]; // [current][left][right]
int data[MAX];

int value(int cur, int pos)
{
	if (!cur) return ZERO;

	return adjcent[cur][pos];
}
int func(int cur, int L, int R)
{
	int step = data[cur];
	if (!step) return 0;
	int& ret = dp[cur][L][R];
	if (ret) return ret;
	return ret = std::min(value(L, step) + func(cur + 1, step, R), value(R, step) + func(cur + 1, L, step));
}
int main()
{
	Init();

	data[0] = 1;
	int i = 0;
	while (data[i++])
	{
		std::cin >> data[i];
	}

	std::cout << func(1, 0, 0);
}