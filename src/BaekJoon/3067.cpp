#include <iostream>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 1e4 + 1;

std::vector<int> result;
int data[20 + 1], DP[20 + 1][MAX];
int N, M, T;

int func(int cur, int value)
{
	if (value == 0)
		return 1;
	if (cur == N)
		return 0;

	auto &ret = DP[cur][value];

	if (ret)
		return ret;

	int current = data[cur];
	int action = value / current;

	for (int i = 0; i <= action; ++i)
	{
		ret += func(cur + 1, value);
		value -= current;
	}

	return ret;
}
int main()
{
	Init();

	std::cin >> T;

	while (T--)
	{
		std::cin >> N;

		for (int i = N - 1; i >= 0; --i)
		{
			std::cin >> data[i];
		}

		std::cin >> M;

		result.push_back(func(0, M));

		for (int y = 0; y < MAX; ++y)
		{
			for (int x = 0; x < 21; ++x)
			{
				DP[x][y] = 0;
			}
		}
	}

	for (auto p : result)
	{
		std::cout << p << "\n";
	}
}