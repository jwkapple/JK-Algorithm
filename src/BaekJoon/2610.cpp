#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 100 + 1;

std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
std::vector<int> data[MAX]; // 위원회 정보
std::vector<int> result;
int map[MAX][MAX];
int visited[MAX];
int N, M;

int func(int cur)
{
	int min = 102;
	int ret = 0;
	auto arr = data[cur];
	int size = data[cur].size();

	for (int y = 0; y < size; ++y)
	{
		int max = 0;
		int Y = arr[y];
		for (int x = 0; x < size; ++x)
		{
			if (y == x) continue;

			int X = arr[x];

			max = std::max(max, map[Y][X]);
		}

		if (min > max) { min = max; ret = Y; }
	}

	return ret;
}

int main()
{
	Init();

	std::cin >> N >> M;

	int from, to, current = 0;

	for (int i = 0; i < M; ++i)
	{
		std::cin >> from >> to;

		pq.push(pii(from, to));
	}


	for (int i = 0; i < M; ++i)
	{
		auto[from, to] = pq.top(); pq.pop();

		map[from][to] = 1; map[to][from] = 1;
		int F = visited[from];
		int T = visited[to];
		if (F)
		{
			if (T) continue;

			data[F].push_back(to);
			visited[to] = F;
		}
		else
		{
			if (T)
			{
				data[T].push_back(from);
				visited[from] = T;
			}

			else
			{
				current++;
				data[current].push_back(from); visited[from] = current;
				data[current].push_back(to);   visited[to] = current;
			}
		}
	}

	for (int cur = 1; cur <= N; ++cur)
	{
		for (int y = 1; y <= N; ++y)
		{
			for (int x = 1; x <= N; ++x)
			{
				if (y == x || y == cur || x == cur) continue;
				if (!map[y][cur] || !map[x][cur]) continue;

				int total = map[y][cur] + map[x][cur];
				if (!map[y][x]) { map[y][x] = total; map[x][y] = total; }
				else
				{
					int ret = std::min(map[y][x], total);
					map[y][x] = ret; map[x][y] = ret;
				}

			}
		}
	}

	for (int i = 1; i <= current; ++i)
	{
		result.push_back(func(i));
	}

	for (int i = 1; i <= N; ++i)
	{
		if (!visited[i]) result.push_back(i);
	}

	std::sort(result.begin(), result.end());

	int size = result.size();
	std::cout << size << "\n";
	for (int i = 0; i < size; ++i)
	{
		std::cout << result[i] << "\n";
	}
}