#include <iostream>

const int MAX = 101;

int left[MAX][MAX];
int right[MAX][MAX];
int result[MAX][MAX];

int N, M, K;

int main()
{
	std::cin >> N >> M;

	for (int i = 0;i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			std::cin >> left[i][j];
		}
	}

	std::cin >> M >> K;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < K; j++)
		{
			std::cin >> right[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			for (int k = 0; k < M; k++)
			{
				result[i][j] += left[i][k] * right[k][j];
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			std::cout << result[i][j] << " ";
		}

		std::cout << "\n";
	}
}
