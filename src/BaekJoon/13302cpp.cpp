#include <iostream>
#include <algorithm>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

enum Cost { ONE = 10000, THREE = 25000, FIVE = 37000 };
const int MAX = 100 + 1;
const int IMPOSSIBLE = 37 * 1e5;

int N, M;
int dp[MAX][41]; // [day][ticket]
bool holiday[MAX];

int func(int current, int ticket)
{
	if (ticket < 0) return IMPOSSIBLE;
	if (current > N) return 0;

	auto& ret = dp[current][ticket];

	if (holiday[current]) return ret = func(current + 1, ticket);
	if (ret) return ret;

	ret = std::min(func(current + 1, ticket) + ONE, func(current + 3, ticket + 1) + THREE);
	ret = std::min(ret, func(current + 5, ticket + 2) + FIVE);
	ret = std::min(ret, func(current + 1, ticket - 3));

	return ret;
}

int main()
{
	Init();

	std::cin >> N >> M;

	int tmp;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> tmp;
		holiday[tmp] = true;
	}

	std::cout << func(1, 0);
}