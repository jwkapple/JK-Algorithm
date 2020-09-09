#include <iostream>
#include <string>

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 6;

int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
std::string data[MAX];
bool visited[MAX][MAX];

int result = 0;
int dist = 0;
int R, C, K;

void back(int x, int y)
{
	if (dist == K && x == R - 1 && y == C - 1)
	{
		result++;
		return;
	}

	for (int i = 0;i < 4; i++)
	{
		int X = x + dir[i][0];
		int Y = y + dir[i][1];

		if (X >= 0 && X < R && Y >= 0 && Y < C)
		{
			if (!visited[X][Y] && data[X][Y] != 'T')
			{
				visited[X][Y] = true;
				dist++;
				back(X, Y);

				visited[X][Y] = false;
				dist--;
			}
		}
	}
}

int main()
{
	Init();

	std::cin >> R >> C >> K;

	for (int i = R - 1; i >= 0; i--)
	{
		std::cin >> data[i];
	}

	dist++;
	visited[0][0] = true;
	back(0, 0);

	std::cout << result;
}