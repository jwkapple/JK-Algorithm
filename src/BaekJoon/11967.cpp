#include <iostream>
#include <vector>
#include <queue>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

int dir[4][2]{ {-1,0},{1,0},{0,-1},{0, 1} };
const int MAX = 200 + 1;

std::vector<pii> data[MAX][MAX];
std::queue<pii> Q;
bool visited[MAX][MAX], light[MAX][MAX];
int N, M, result = 1;

int main()
{
	Init();

	std::cin >> N >> M;

	int y, x, a, b;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> y >> x >> a >> b;

		data[y][x].push_back(pii(a, b));
	}

	Q.push(pii(1, 1));
	light[1][1] = true;

	while (!Q.empty())
	{
		auto[y, x] = Q.front(); Q.pop();

		if (visited[y][x]) continue;
		visited[y][x] = true;

		for (auto p : data[y][x])
		{
			auto[pY, pX] = p;

			if (light[pY][pX]) continue;
			light[pY][pX] = true;
			result++;

			for (int i = 0; i < 4; ++i)
			{
				int Y = pY + dir[i][0];
				int X = pX + dir[i][1];

				if (visited[Y][X])
				{
					Q.push(pii(pY, pX));
					break;
				}
			}
		}

		for (int i = 0; i < 4; ++i)
		{
			int Y = y + dir[i][0];
			int X = x + dir[i][1];

			if (light[Y][X] && !visited[Y][X]) Q.push(pii(Y, X));
		}
	}

	std::cout << result;
}