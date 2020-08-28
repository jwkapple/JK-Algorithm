#include <iostream>

const int MAX = 128;

int pos[4][2] = { {0,0},{1,0},{0,1},{1,1} };
int data[MAX][MAX];
int bl = 0, wh = 0;
int N;

int func(int x, int y, int N) // 0 == black / 1 == white / 2 == done
{
	if (N / 2 == 0)	return data[x][y];
	int quad = N / 2;

	int black = 0, white = 0;

	for (int i = 0;i < 4; i++)
	{
		int X = x + quad * pos[i][0];
		int Y = y + quad * pos[i][1];
		int tmp = func(X, Y, N / 2);
		if (tmp == 1) white++;
		else if (tmp == 0)black++;
	}

	if (black + white != 4)
	{
		wh += white;
		bl += black;
		return 2;
	}

	else
	{
		if (white == 0) return 0;
		if (black == 0) return 1;

		bl += black;
		wh += white;

		return 2;
	}
}

int main()
{
	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0;j < N; j++)
		{
			std::cin >> data[i][j];
		}
	}

	func(0, 0, N);

	std::cout << bl << "\n" << wh;
}