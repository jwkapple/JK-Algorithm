#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 1000 + 1;

bool DP[1e9][MAX];
int data[MAX];
int N;

bool func(int value, int cur)
{
	auto &dp = DP[value][cur];
	if (value % 7 == 4)
	{
		return true;
	}

	if (cur == N)
		return false;

	if (func(value + data[cur], cur + 1))
	{
		return true;
	}
	else
	{
		if (func(value, cur + 1))
		{
			return true;
		}
	}

	return false;
}
int main()
{
	Init();

	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> data[i];
	}

	if (func(0, 0))
	{
		std::cout << "YES";
	}
	else
		std::cout << "NO";
}