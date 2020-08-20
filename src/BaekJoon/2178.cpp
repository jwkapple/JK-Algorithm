#include <iostream>
#include <string>
#include <queue>

const int MAX = 101;
std::string tmp[MAX];

int direction[4][2] = { {1,0}, {-1,0}, {0,1},{0,-1} };
int data[MAX][MAX];
bool visited[MAX][MAX];
std::queue<std::pair<int, int>> q;

int result;
int N, M;

void bfs()
{

	std::pair<int, int> current;

	while (!q.empty())
	{
		current = q.front();
		q.pop();

		if (current.first == N && current.second == M)
		{
			result = data[current.first][current.second];
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int x = current.first + direction[i][0];
			int y = current.second + direction[i][1];

			if (1 <= x && x <= N && 1 <= y && y <= M && data[x][y] == 1)
			{
				q.push(std::make_pair(x, y));

				data[x][y] = data[current.first][current.second] + 1;
			}
		}
	}
}
int main()
{
	std::cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		std::cin >> tmp[i];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			switch (tmp[i][j - 1])
			{
			case '1':
				data[i][j] = 1;
				break;

			case '0':
				data[i][j] = 0;
				break;
			}
		}
	}

	q.push(std::make_pair(1, 1));
	bfs();

	std::cout << result;
}