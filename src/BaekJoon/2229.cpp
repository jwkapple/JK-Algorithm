#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1000 + 1;

int data[MAX], DP[MAX], GDP[MAX][MAX];
int N;

void gap()
{
	int max, min;
	for (int i = 0; i < N; ++i)
	{
		max = data[i];
		min = data[i];

		for (int j = i; j < N; ++j)
		{
			min = min > data[j] ? data[j] : min;
			max = max > data[j] ? max : data[j];
			GDP[i][j] = max - min;
		}
	}
}

int main()
{
	Init();

	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> data[i];
	}

	gap();

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			if (!j) DP[i] = DP[i] > GDP[j][i] ? DP[i] : GDP[j][i];
			else DP[i] = DP[i] > DP[j] + GDP[j + 1][i] ? DP[i] : DP[j] + GDP[j + 1][i];
		}
	}

	std::cout << DP[N - 1];
}