#include <iostream>
#include <climits>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 500 + 1;

int DP[MAX][MAX];
int total[MAX];
pii data[MAX];
int N;

int main()
{
	Init();

	std::cin >> N;

	int r, c;
	for (int i = 1; i <= N; ++i)
	{
		std::cin >> r >> c;
		data[i] = pii(r, c);
	}

	for (int i = 1; i < N; ++i)
	{
		for (int j = 1; i + j <= N; ++j)
		{
			DP[j][i + j] = INT_MAX;
			for (int k = j; k <= i + j; ++k)
			{
				int value = DP[j][k] + DP[k + 1][i + j] + data[j].first * data[k].second * data[i + j].second;
				DP[j][i + j] = DP[j][i + j] > value ? value : DP[j][i + j];
			}
		}
	}

	std::cout << DP[1][N];
}