#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 101;

int data[MAX][MAX];
int N, M;
int main()
{
	Init();

	std::cin >> N >> M;

	int src, dst, v;
	for (int a = 0; a < M; ++a)
	{
		std::cin >> src >> dst >> v;

		if (!data[src][dst] || data[src][dst] > v) data[src][dst] = v;
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int y = 1; y <= N; ++y)
		{
			if (y == i) continue;

			for (int x = 1; x <= N; ++x)
			{
				if (x == i || !data[y][i] || !data[i][x] || y == x) continue;

				int cur = data[y][i] + data[i][x];
				if (!data[y][x]) data[y][x] = cur;
				else data[y][x] = data[y][x] > cur ? cur : data[y][x];
			}
		}
	}

	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= N; ++x)
		{
			std::cout << data[y][x] << " ";
		}

		std::cout << "\n";
	}
}