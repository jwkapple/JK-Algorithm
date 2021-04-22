#include <iostream>
#include <vector>
#include <queue>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

int dir[8][2]{ {-1, 0},{1,0},{0,-1},{0, 1},{-1, -1},{-1, 1},{1, -1}, {1, 1} };

const int MAX = 10 + 1;

int visited[MAX][MAX];
int data[MAX][MAX], map[MAX][MAX];
std::priority_queue<int, std::vector<int>, std::greater<int>> tree[MAX][MAX];
int N, M, K, result = 0;

void func(int y, int x, int num)
{
	for (int i = 0; i < 8; ++i)
	{
		int Y = y + dir[i][0];
		int X = x + dir[i][1];

		if (Y > 0 && Y <= N && X > 0 && X <= N)
		{
			for (int j = 0; j < num; ++j) tree[Y][X].push(1);
		}
	}
}
int main()
{
	Init();

	std::cin >> N >> M >> K;

	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= N; ++x)
		{
			std::cin >> map[y][x];
			data[y][x] = 5;
		}
	}

	int y, x, age;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> y >> x >> age;

		tree[y][x].push(age);
	}

	while (K--)
	{
		// Spring & Summer
		for (int y = 1; y <= N; ++y)
		{
			for (int x = 1; x <= N; ++x)
			{
				if (tree[y][x].size() == 0) continue;

				std::vector<int> tmp;
				int total = 0;
				auto& current = tree[y][x];
				int size = current.size();

				for (int i = 0; i < size; ++i)
				{
					int cur = current.top(); current.pop();

					if (data[y][x] >= cur)
					{
						int score = cur + 1;
						tmp.push_back(score);
						if (score % 5 == 0 && score != 0) visited[y][x]++;
						data[y][x] -= cur;
					}
					else total += cur / 2;
				}

				data[y][x] += total;
				for (auto p : tmp) { current.push(p); }
			}
		}

		// Autumn
		for (int y = 1; y <= N; ++y)
		{
			for (int x = 1; x <= N; ++x)
			{
				if (!visited[y][x]) continue;

				func(y, x, visited[y][x]);

				visited[y][x] = 0;
			}
		}

		// Winter
		for (int y = 1; y <= N; ++y)
		{
			for (int x = 1; x <= N; ++x)
			{
				data[y][x] += map[y][x];
			}
		}
	}

	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= N; ++x)
		{
			result += tree[y][x].size();
		}
	}

	std::cout << result;
}