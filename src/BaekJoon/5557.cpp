#include <iostream>
#include <string.h>

#define ll long long

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 100 + 1;

ll DP[MAX], result[MAX];
int data[MAX];
int N, M;

int main()
{
	Init();

	std::cin >> N;

	for (int i = 0; i < N - 1; ++i)
	{
		std::cin >> data[i];
	}

	std::cin >> M;

	DP[data[0]] = 1;

	for (int i = 1; i < N - 1; ++i)
	{
		memset(result, 0, sizeof(result));
		for (int j = 0; j <= 20; ++j)
		{
			if (DP[j])
			{
				if ((j + data[i]) <= 20) result[(j + data[i])] += DP[j];
				if ((j - data[i]) >= 0) result[(j - data[i])] += DP[j];
			}
		}

		for (int j = 0; j <= 20; ++j) DP[j] = result[j];
	}

	std::cout << result[M] << '\n';
}