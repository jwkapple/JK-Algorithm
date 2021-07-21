#include <iostream>
#include <stdlib.h>
#include <vector>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 100 + 3;

std::vector<bool> result;
int map[MAX][MAX];
pii data[MAX];
bool visited[MAX];

int T, N;

bool DFS(int cur, int num)
{
	if (visited[cur]) return false;
	visited[cur] = true;

	if (cur == num) return true;
	auto[y, x] = data[cur];

	for (int i = 1; i <= num; ++i)
	{
		if (visited[num]) continue;

		auto[tY, tX] = data[i];

		if (!map[cur][i]) map[cur][i] = std::abs(tY - y) + std::abs(tX - x);

		if (map[cur][i] <= 1000) if (DFS(i, num)) return true;
	}

	return false;
}
int main()
{
	Init();

	std::cin >> T;

	int y, x, cur;
	while (T--)
	{
		cur = 1;

		std::cin >> N;

		std::cin >> y >> x;
		data[cur++] = pii(y, x);

		for (int i = 0; i < N; ++i)
		{
			std::cin >> y >> x;
			data[cur++] = pii(y, x);
		}

		std::cin >> y >> x;
		data[cur++] = pii(y, x);

		result.push_back(DFS(1, N + 2));

		for (y = 1; y <= N + 2; ++y)
		{
			for (x = 1; x <= N + 2; ++x)
			{
				map[y][x] = 0;
			}
		}

		for (int i = 1; i <= N + 2; ++i) visited[i] = false;
	}

	for (auto p : result)
	{
		if (p) std::cout << "happy" << "\n";
		else   std::cout << "sad" << "\n";
	}
}