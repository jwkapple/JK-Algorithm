#include <iostream>
#include <algorithm>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 300 + 1;

int N, M, d[21][MAX], e[21][MAX], v[21][MAX], i, j, k, s, a[21];

int main()
{
	std::cin >> N >> M;

	int tmp;
	for (i = 1;i <= N;++i)
	{
		std::cin >> tmp;
		for (j = 1;j <= M;++j)
		{
			std::cin >> d[j][i];
		}
	}

	for (i = 1;i <= M;i++)
	{
		for (j = 1;j <= N;j++)
		{
			for (k = 0;k <= j;k++)
			{
				if (e[i][j] < e[i - 1][j - k] + d[i][k])
				{
					e[i][j] = e[i - 1][j - k] + d[i][k];
					v[i][j] = k;
				}
			}
		}
	}

	std::cout << e[M][N] << "\n";
	for (j = N, i = M;i;--i)
	{
		a[i] = v[i][j];
		j -= v[i][j];
	}
	for (i = 1;i <= M; ++i)
	{
		std::cout << a[i];
	}
}