#include <iostream>
#include <queue>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

int dir[4][2]{ {-1,0},{1,0},{0,-1},{0,1} };
const int MAX = 100 + 1;

bool visited[MAX][MAX];
char data[MAX][MAX];
int N, A = 0, B = 0;

void func(int y, int x, bool s)
{
	std::queue<pii> Q;
	Q.push(pii(y, x));

	while (!Q.empty())
	{
		auto[y, x] = Q.front(); Q.pop();
		if (visited[y][x]) continue;

		visited[y][x] = true;
		char cur = data[y][x];
		for (int i = 0; i < 4; ++i)
		{
			int Y = y + dir[i][0];
			int X = x + dir[i][1];

			if (Y > 0 && Y <= N && X > 0 && Y <= N)
			{
				if (s)
				{
					if (data[Y][X] == cur) Q.push(pii(Y, X));
				}
				else
				{
					if (cur == 'R' || cur == 'G')
					{
						if (data[Y][X] == 'R' || data[Y][X] == 'G') Q.push(pii(Y, X));
					}
					else
					{
						if (data[Y][X] == 'B') Q.push(pii(Y, X));
					}
				}
			}
		}
	}

	if (s) A++;
	else B++;
}
int main()
{
	Init();

	std::cin >> N;

	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= N; ++x)
		{
			std::cin >> data[y][x];
		}
	}

	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= N; ++x)
		{
			if (visited[y][x]) continue;
			else func(y, x, true);
		}
	}

	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= N; ++x)
		{
			visited[y][x] = false;
		}
	}
	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= N; ++x)
		{
			if (visited[y][x]) continue;
			else func(y, x, false);
		}
	}

	std::cout << A << " " << B;
}