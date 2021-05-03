#include <iostream>

const int MAX = 17;
int dir[8][2]{ {1,0}, {-1,0}, {0,1}, {0,-1}, {1,1},{1,-1},{-1,1},{-1,-1} };

int board[MAX][MAX];

int N, result = 0;

void Fill(int x, int y, bool side)
{
	int X = x, Y = y;

	if (side) board[x][y]++;
	else board[x][y]--;

	for (int i = 0; i < 8; i++)
	{
		x = X, y = Y;

		while (x <= N && y <= N && x >= 1 && y >= 1) // º¸µå ¾È
		{
			x += dir[i][0];
			y += dir[i][1];

			if (x <= N && y <= N && x >= 1 && y >= 1)
			{
				if (side) board[x][y]++;
				else board[x][y]--;
			}
		}
	}
}

void back(int line)
{
	if (line == N + 1)
	{
		result++;
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (board[line][i] == 0)
		{
			Fill(line, i, true);
			back(line + 1);
			Fill(line, i, false);
		}
	}
}

int main()
{
	std::cin >> N;

	back(1);
	std::cout << result;
}