#include <iostream>
#include <algorithm>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 100 + 1;

std::vector<int> result;
int data[MAX][MAX];
int T, N, M, K;

int main()
{
	Init();

	std::cin >> T;

	int from, to, v, tmp;
	while (T--)
	{
		std::vector<int> friends;

		std::cin >> N >> M;

		for (int i = 0; i < M; ++i)
		{
			std::cin >> from >> to >> v;

			data[from][to] = v;
			data[to][from] = v;
		}

		std::cin >> K;

		for (int i = 0; i < K; ++i)
		{
			std::cin >> tmp;
			friends.push_back(tmp);
		}

		for (int a = 1; a <= N; ++a)
		{
			for (int y = 1; y <= N; ++y)
			{
				if (y == a)
					continue;
				for (int x = 1; x <= N; ++x)
				{
					if (y == x || x == a)
						continue;
					if (!data[y][a] || !data[a][x])
						continue;

					v = data[y][a] + data[a][x];
					if (!data[y][x])
					{
						data[y][x] = v;
						data[x][y] = v;
					}
					else
					{
						if (data[y][x] > v)
						{
							data[y][x] = v;
							data[x][y] = v;
						}
					}
				}
			}
		}

		int total = 1e9 + 1;
		int num = 0;
		for (int i = N; i > 0; --i)
		{
			tmp = 0;
			for (auto p : friends)
			{
				tmp += data[p][i];
			}

			if (total >= tmp)
			{
				total = tmp;
				num = i;
			}
		}

		result.push_back(num);
		for (int i = 1; i <= N; ++i)
		{
			std::fill(data[i], data[i] + MAX, 0);
		}
	}

	for (auto p : result)
	{
		std::cout << p << "\n";
	}
}