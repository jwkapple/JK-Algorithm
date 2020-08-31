#include <iostream>
#include <vector>
#include <queue>

const int MAX = 1e3 + 1;

int N, M;
int H, W;
int Sr, Sc, Fr, Fc;

int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int board[MAX][MAX];
bool visited[MAX][MAX];
bool no;

std::queue<std::pair<int, int>> q;
std::vector<std::pair<int, int>> wall;

int result = 0;

bool isIn(int x, int y) // return true if the wall is in box
{
	for (int i = 0;i < wall.size(); i++)
	{
		int wallX = wall[i].first;
		int wallY = wall[i].second;
		bool tmp = (wallX >= x && wallX <= x + H - 1 && wallY >= y && wallY <= y + W - 1);

		if (tmp) return true;
	}

	return false;
}
void func()
{
	while (!q.empty())
	{
		int size = q.size();

		for (int a = 0; a < size; a++)
		{
			std::pair<int, int> current = q.front();

			if (current.first == Fr && current.second == Fc) return;

			q.pop();

			for (int i = 0;i < 4; i++)
			{
				int x = current.first + dir[i][0];
				int y = current.second + dir[i][1];

				if (!visited[x][y])
				{
					if (x >= 1 && x <= N && y >= 1 && y <= M)
					{
						if (x + H - 1 >= 1 && x + H - 1 <= N && y + W - 1 >= 1 && y + W - 1 <= M)
						{
							if (!isIn(x, y))
							{
								visited[x][y] = true;
								q.push(std::make_pair(x, y));
							}
						}
					}
				}
			}

		}
		if (!q.empty()) result++;
	}
	no = true;
}

int main()
{
	std::cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			int tmp;
			std::cin >> tmp;

			if (tmp == 1) wall.push_back(std::make_pair(i, j));

			board[i][j] = tmp;
		}
	}

	std::cin >> H >> W >> Sr >> Sc >> Fr >> Fc;

	q.push(std::make_pair(Sr, Sc));

	func();


	if (no)
	{
		std::cout << -1;
	}

	else
	{
		std::cout << result;
	}
}