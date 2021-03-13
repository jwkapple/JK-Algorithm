#include <iostream>
void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

int dir[4][2]{ {-1,0},{1,0},{0,-1},{0,1} };
enum direction { UP, DOWN, LEFT, RIGHT };
const int MAX = 1000 + 1;

int data[MAX][MAX], map[MAX][MAX];
int N, M, result = 1;

int func(int y, int x, int v)
{
	auto& ret = data[y][x];
	auto value = map[y][x];
	if (ret)
	{
		if (data[y][x] == v)
		{
			result++;
			return v;
		}
		else
		{
			return ret;
		}
	}

	ret = result;

	return ret = func(y + dir[value][0], x + dir[value][1], ret);
}
int main() {

	Init();

	std::cin >> N >> M;

	char tmp;
	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= M; ++x)
		{
			auto& cur = map[y][x];
			std::cin >> tmp;

			switch (tmp)
			{
			case 'U': cur = UP;   break;
			case 'D': cur = DOWN; break;
			case 'L': cur = LEFT;	break;
			case 'R': cur = RIGHT; break;
			}
		}
	}

	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= M; ++x)
		{
			if (data[y][x]) continue;

			func(y, x, result);
		}
	}

	std::cout << result - 1;
}