#include <iostream>
#include <vector>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int INF = 1e9;
const int MAX = 500 + 1;

std::vector<int> result;
int DP[MAX][MAX];
int data[MAX];

int T, N;

int main()
{
	Init();

	std::cin >> T;

	while (T--)
	{
		std::cin >> N;

		int tmp;
		for (int i = 1; i <= N; ++i)
		{
			std::cin >> tmp;
			data[i] = data[i - 1] + tmp;
		}

		for (int i = 1; i < N; ++i)
		{
			for (int j = 1; i + j <= N; ++j)
			{
				auto& cur = DP[j][i + j];
				cur = INF;
				for (int k = j; k <= i + j; ++k)
				{
					int value = DP[j][k] + DP[k + 1][i + j] + data[i + j] - data[j - 1];
					cur = value > cur ? cur : value;
				}
			}
		}

		result.push_back(DP[1][N]);
	}

	for (auto p : result)
	{
		std::cout << p << "\n";
	}
}