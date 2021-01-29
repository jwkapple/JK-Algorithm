#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1000 + 1;

bool visited[MAX][MAX];
int data[MAX][MAX], h[MAX][MAX], w[MAX][MAX];
int dp[MAX][MAX];
int N, M, result = 0;

int Height(int y, int x)
{
	if (!data[y][x]) return 0;
	auto& cur = h[y][x];
	if (cur) return cur;
	else return cur = Height(y + 1, x) + 1;
}

int Width(int y, int x)
{
	if (!data[y][x]) return 0;
	auto& cur = w[y][x];
	if (cur) return cur;
	else return cur = Width(y, x + 1) + 1;
}

int Size(int y, int x)
{
	auto& cur = dp[y][x];
	if (cur) return cur;

	int height = Height(y, x);
	int width = Width(y, x);

	return cur = height > width ? width : height;
}
int func(int y, int x)
{
	visited[y][x] = true;

	if (!data[y][x]) return 1;

	auto cur = Size(y, x);
	int tmp = func(y + 1, x + 1);
	if (tmp + 1 < cur) cur = tmp + 1;

	result = result > cur ? result : cur;

	return cur;
}
int main()
{
	Init();

	std::cin >> N >> M;

	char tmp;
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			std::cin >> tmp;
			data[y][x] = tmp - '0';
		}
	}

	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			if (!data[y][x] || visited[y][x]) continue;

			func(y, x);
		}
	}

	std::cout << result * result;
}