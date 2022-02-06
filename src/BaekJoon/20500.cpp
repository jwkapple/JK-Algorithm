#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int DIV = 1e9 + 7;
const int MAX = 1515 + 1;

int dp[MAX][MAX * 5];
int N;

int func(int num, int total)
{
	if (num == N)
	{
		return (total % 3 == 0);
	}

	auto &ret = dp[num][total];
	if (ret)
		return ret;

	return ret =
			   ((func(num + 1, total + 1) % DIV) + (func(num + 1, total + 5) % DIV)) % DIV;
}
int main()
{
	Init();

	std::cin >> N;

	std::cout << func(1, 5) % DIV;
}