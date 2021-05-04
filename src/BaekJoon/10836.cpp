#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 700 + 1;

int map[MAX][MAX], data[MAX * 2];
int M, N;

int main()
{
	Init();

	std::cin >> M >> N;

	for (int y = 0; y < M; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			map[y][x] = 1;
		}
	}
	int cur = 0;
	int zero, one, two;
	int tmp = 0;
	for (int i = 0;i < N; ++i)
	{
		std::cin >> zero >> one >> two;

		data[zero]++;
		one += zero;
		data[one]++;
	}

	for (int y = M - 1; y >= 0; --y)
	{
		tmp += data[cur++];
		map[y][0] += tmp;
	}


	for (int x = 1; x <= M - 1; ++x)
	{
		tmp += data[cur++];
		map[0][x] += tmp;
	}

	for (int y = 1; y < M; ++y)
	{
		for (int x = 1; x < M; ++x)
		{
			map[y][x] = map[0][x];
		}
	}
	for (int y = 0; y < M; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			std::cout << map[y][x] << " ";
		}
		std::cout << "\n";
	}
}
