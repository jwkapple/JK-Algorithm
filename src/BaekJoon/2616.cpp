#include <iostream>
#include <queue>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 5e4 + 1;

int data[MAX], DP[MAX][3];
int N, X;

int func(int cur, int num)
{
	if (num == 3 || cur > N - X * (3 - num))
	{
		return 0;
	}

	auto &ret = DP[cur][num];

	if (ret)
		return ret;

	int on = 0, off = 0;

	for (int i = 0; i < X; ++i)
	{
		on += data[cur + i];
	}

	on += func(cur + X, num + 1);
	off = func(cur + 1, num);

	return ret = on > off ? on : off;
}

int main()
{
	Init();

	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> data[i];
	}

	std::cin >> X;

	std::cout << func(0, 0);
}