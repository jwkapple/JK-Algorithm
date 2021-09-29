#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 110;
bool DP[MAX][1010];
int data[MAX];
int N, S, M;

int main()
{
	Init();

	std::cin >> N >> S >> M;
	for (int i = 1; i <= N; ++i) { std::cin >> data[i]; }

	if (S + data[1] <= M) DP[1][S + data[1]] = true;
	if (S - data[1] >= 0) DP[1][S - data[1]] = true;

	for(int i = 2; i <= N; ++i)
	{
		for (int j = 0; j <= M; ++j)
		{
			if (DP[i - 1][j])
			{
				if (j + data[i] <= M) DP[i][j + data[i]] = true;
				if (j - data[i] >= 0) DP[i][j - data[i]] = true;
			}
		}
	}

	bool done = false;
	for (int i = M; i >= 0; --i)
	{
		if (DP[N][i])
		{
			std::cout << i << "\n";
			done = true;
			break;
		}
	}

	if (!done) std::cout << -1 << "\n";
}