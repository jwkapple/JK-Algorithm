#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 5e4 + 1;
const int DIV = 1e9 + 9;

int DP[MAX][3];
int N, result = 0;

int func(int value, int prev)
{
	if (value == N + 1)
		return 0;
	if (value == N || value == N - 1)
		return 1;

	auto &ret = DP[value][prev];

	if (ret) return ret;

	switch (prev)
	{
	case 1:
		return ret = DP[value][4] = func(value + 1, 1) % DIV + func(value + 2, 2) % DIV;

	case 2:
		return func(value - 1, 3) % DIV;

	case 3:
		return func(value + 2, 4) % DIV;

	case 4:
		return DP[value][1] = ret = func(value + 1, 1) % DIV + func(value + 2, 2) % DIV;
	}
	if (prev == 1) 
	

	return 0;
}

int main()
{
	Init();

	std::cin >> N;

	std::cout << func(1, 1) % DIV;
}