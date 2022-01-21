#include <iostream>
#include <vector>
#include <queue>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

const int MAX = 100 + 1;

std::priority_queue<int, std::vector<int>, std::greater<int>> Q;
int data[MAX][MAX], visited[MAX][MAX];
bool visit[MAX];
int N, value, result = 1;

void BFS(int y, int x)
{
	std::queue<pii> PQ;

	PQ.push(pii(y, x));

	while (!PQ.empty())
	{
		auto [tY, tX] = PQ.front();
		PQ.pop();

		for (int i = 0; i < 4; ++i)
		{
			int Y = tY + dir[i][0];
			int X = tX + dir[i][1];

			if (Y > 0 && Y <= N && X > 0 && X <= N)
			{
				if (data[Y][X] > value)
				{
					if (visited[Y][X] < value)
					{
						visited[Y][X] = value;
						PQ.push(pii(Y, X));
					}
				}
			}
		}
	}
}
int main()
{
	Init();

	std::cin >> N;

	int tmp;
	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= N; ++x)
		{
			std::cin >> tmp;
			data[y][x] = tmp;
			if (!visit[tmp])
			{
				visit[tmp] = true;
				Q.push(tmp);
			}
		}
	}

	while (!Q.empty())
	{
		value = Q.top();
		Q.pop();

		int cur = 0;
		for (int y = 1; y <= N; ++y)
		{
			for (int x = 1; x <= N; ++x)
			{
				if (data[y][x] > value)
				{
					if (visited[y][x] < value)
					{
						BFS(y, x);
						cur++;
					}
				}
			}
		}

		result = result > cur ? result : cur;
	}

	std::cout << result;
}