#include <iostream>
#include <algorithm>
#include <vector>

#define Input(from, to, v) data[from][to] = v, data[to][from] = v

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 100 + 1;

std::vector<int> result;
bool visited[MAX];
int data[MAX][MAX];
int value[MAX];
int N, M;

int main()
{
	Init();

	std::cin >> N >> M;

	int from, to;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> from >> to;

		value[from] = value[to] = 1;
		Input(from, to, 1);
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int y = 1; y <= N; ++y)
		{
			if (y == i) continue;
			for (int x = 1; x <= N; ++x)
			{
				if (x == i || !data[y][i] || !data[i][x] || y == x) continue;

				int nValue = data[y][i] + data[i][x];
				if (!data[y][x])
				{
					Input(y, x, nValue);
					continue;
				}

				if (data[y][x] > nValue)Input(y, x, nValue);
			}
		}
	}

	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= N; ++x)
		{
			if (data[y][x] > value[y]) value[y] = data[y][x];
		}
	}
	for (int i = 1; i <= N; ++i)
	{
		if (!value[i])
		{
			visited[i] = true;
			result.push_back(i);
			continue;
		}

		if (visited[i]) continue;

		visited[i] = true;
		int min = value[i];
		int minN = i;
		for (int j = 1; j <= N; ++j)
		{
			if (data[i][j])
			{
				visited[j] = true;
				if (min > value[j])
				{
					min = value[j];
					minN = j;
				}
			}
		}

		result.push_back(minN);
	}

	std::sort(result.begin(), result.end());
	std::cout << result.size() << "\n";
	for (auto p : result)
	{
		std::cout << p << "\n";
	}
}