#include <iostream>
#include <vector>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 1e4 + 1;

std::vector<pii> data;
int DP[1000 + 1][MAX];
int N, K;

int func(int cur, int remain)
{
	if (remain <= 0 || cur == K)
		return 0;

	auto &ret = DP[cur][remain];

	if (ret)
		return ret;

	auto [important, time] = data[cur];

	int on, off;

	on = remain >= time ? func(cur + 1, remain - time) + important : 0;
	off = func(cur + 1, remain);

	return ret = on > off ? on : off;
}

int main()
{
	Init();

	std::cin >> N >> K;

	int I, T;
	for (int i = 0; i < K; ++i)
	{
		std::cin >> I >> T;
		data.push_back(pii(I, T));
	}

	std::cout << func(0, N);
}
