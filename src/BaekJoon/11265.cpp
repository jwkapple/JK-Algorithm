#include <iostream>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 500 + 1;

std::vector<bool> result;
int data[MAX][MAX];
int N, M;

int main()
{
	Init();

	std::cin >> N >> M;

	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= N; ++x)
		{
			std::cin >> data[y][x];
		}
	}

	for (int a = 1; a <= N; ++a)
	{
		for (int y = 1; y <= N; ++y)
		{
			if (y == a || !data[y][a])
				continue;
			for (int x = 1; x <= N; ++x)
			{
				if (x == a || y == x || !data[a][x])
					continue;

				int cur = data[y][x];
				int value = data[y][a] + data[a][x];

				if (cur)
					data[y][x] = cur > value ? value : cur;
				else
					data[y][x] = value;
			}
		}
	}

	int from, to, v;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> from >> to >> v;
		result.push_back(data[from][to] && data[from][to] <= v);
	}

	for (auto p : result)
	{
		if (p)
			std::cout << "Enjoy other party\n";
		else
			std::cout << "Stay here\n";
	}
}