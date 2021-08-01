#include <iostream>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1000 + 5;

std::vector<int> result;
int data[MAX], DP[MAX][MAX];
int T, N;

int func(int from, int to)
{
	auto& ret = DP[from][to];
	if (ret) return ret;

	int L = data[from] - data[from - 1];
	int R = data[to] - data[to - 1];

	if (from + 1 == to) return ret = L > R ? L : R;

	int total = data[to] - data[from - 1];
	int left = total - func(from + 1, to);
	int right = total - func(from, to - 1);

	return ret = left > right ? left : right;
}
int main()
{
	Init();

	std::cin >> T;

	int tmp;
	while (T--)
	{
		std::cin >> N;

		for (int i = 1; i <= N; ++i)
		{
			std::cin >> tmp;
			data[i] = data[i - 1] + tmp;
		}

		result.push_back(func(1, N));

		for (int y = 1; y <= N; ++y)
		{
			for (int x = 1; x <= N; ++x)
			{
				DP[y][x] = 0;
			}
		}
	}

	for (auto p : result)
	{
		std::cout << p << "\n";
	}
}