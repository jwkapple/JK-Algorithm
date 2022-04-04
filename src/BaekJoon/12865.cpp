#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 1e5 + 1;

int DP[2][MAX];
int N, K, W, V;

int main()
{
	Init();

	std::cin >> N >> K;

	bool S;
	int cur, prev;
	for (int a = 1; a <= N; ++a)
	{
		std::cin >> W >> V;

		cur = S;
		prev = !S;

		for (int i = 1; i <= K; ++i)
		{
			if (W <= i)
			{
				int on = DP[prev][i - W] + V;
				int off = DP[prev][i];

				DP[cur][i] = on > off ? on : off;
			}
			else
			{
				DP[cur][i] = DP[prev][i];
			}
		}

		S = !S;
	}

	std::cout << DP[cur][K];
}