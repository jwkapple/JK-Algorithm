#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

int N, M;
int DP[11][31];

int func(int cur, int fruit)
{
	if (cur == N)
		return 1;

	auto &ret = DP[cur][fruit];
	if (ret)
		return ret;

	fruit--;
	int remain = N - cur;
	int total = 0;
	for (int i = remain; i <= fruit; ++i)
	{
		total += func(cur + 1, i);
	}

	return ret = total;
}

int main()
{
	Init();

	std::cin >> N >> M;

	std::cout << func(1, M);
}