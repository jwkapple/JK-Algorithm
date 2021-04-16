#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 30 + 1;

bool ladder[MAX][MAX];

int N, M, H, result = 1e9;

bool down()
{
	for (int y = 1; y <= N; ++y)
	{
		int cur = y;
		for (int x = 1; x <= H; ++x)
		{
			if (ladder[cur][x]) cur++;
			else if (ladder[cur - 1][x]) cur--;
		}

		if (cur != y) return false;
	}

	return true;
}

void func(int cur, int num)
{
	if (num >= 4) return;

	if (down())
	{
		result = result > num ? num : result;
		return;
	}

	for (int y = cur; y <= H; ++y)
	{
		for (int x = 1; x < N; ++x)
		{
			if (ladder[x][y]) continue;
			if (ladder[x - 1][y]) continue;
			if (ladder[x + 1][y]) continue;

			ladder[x][y] = true;
			func(y, num + 1);
			ladder[x][y] = false;
		}
	}
}
int main()
{
	Init();

	std::cin >> N >> M >> H;

	int a, b;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> a >> b;

		ladder[b][a] = true;
	}

	func(1, 0);

	if (result == 1e9) result = -1;

	std::cout << result;
}