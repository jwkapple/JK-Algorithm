#include <iostream>
#include <queue>

const int MAX = 1e3 + 1;

int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
std::queue<std::pair<int, int>> q;

bool rotten = true;
int visited[MAX][MAX];
int total;
int result = 0;

int N, M;

void bfs()
{
	if (q.size() == N * M)
	{
		result = -1;
		return;
	}

	while (!q.empty())
	{
		int size = q.size();

		for (int i = 0;i < size; i++)
		{
			auto current = q.front();
			q.pop();
			visited;
			for (int j = 0; j < 4; j++)
			{
				int x = current.first + dir[j][0];
				int y = current.second + dir[j][1];

				if (x >= 0 && x < M && y >= 0 && y < N)
				{
					if (!visited[x][y])
					{
						visited[x][y] = true;
						total--;
						q.push(std::make_pair(x, y));
					}
				}
			}
		}

		if (!q.empty()) result++;
	}

}
int main()
{
	std::cin >> N >> M;
	total = N * M;
	for (int i = 0;i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int tmp;
			std::cin >> tmp;
			switch (tmp)
			{
			case 1:
				q.push(std::make_pair(i, j));
				visited[i][j] = true;
				total--;
				rotten = false;
				break;
			case 0:
				rotten = false;
				break;
			case -1:
				total--;
				visited[i][j] = true;
				break;
			}
		}
	}

	bfs();

	if (result == -1) std::cout << 0;
	else if (total != 0 || rotten) std::cout << -1;
	else
	{
		std::cout << result;
	}
}