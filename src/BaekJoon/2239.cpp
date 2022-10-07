#include <iostream>
#include <string>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 9;

bool R[MAX][MAX], C[MAX][MAX], S[MAX][MAX];
int data[MAX][MAX];

void func(int cur)
{
	if (cur == 81)
	{
		for (int y = 0; y < MAX; ++y)
		{
			for (int x = 0; x < MAX; ++x)
			{
				std::cout << data[y][x];
			}

			std::cout << "\n";
		}

		exit(0);
	}

	int Y = cur / MAX;
	int X = cur % MAX;

	if (!data[Y][X])
	{
		for (int i = 1; i <= 9; ++i)
		{
			if (!R[Y][i] && !C[X][i] && !S[(Y / 3) * 3 + (X / 3)][i])
			{
				data[Y][X] = i;
				R[Y][i] = true;
				C[X][i] = true;
				S[(Y / 3) * 3 + (X / 3)][i] = true;
				func(cur + 1);
				data[Y][X] = 0;
				R[Y][i] = false;
				C[X][i] = false;
				S[(Y / 3) * 3 + (X / 3)][i] = false;
			}
		}
	}
	else
		func(cur + 1);
}
int main()
{
	Init();

	std::string tmp;

	for (int y = 0; y < MAX; ++y)
	{
		std::cin >> tmp;

		for (int x = 0; x < MAX; ++x)
		{
			if (tmp[x] != '0')
			{
				int value = tmp[x] - '0';
				data[y][x] = value;
				R[y][value] = true;
				C[x][value] = true;
				S[(y / 3) * 3 + (x / 3)][value] = true;
			}
		}
	}

	func(0);
}