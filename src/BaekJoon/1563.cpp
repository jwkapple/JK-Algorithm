#include <iostream>
#include <vector>

#define ll long long

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e4 + 1;
const int DIV = 1e6;

ll DP[MAX][2][3]; // [출석일][지각][결석]

int N;

ll func(int cur, int late, int abs)
{
	auto& ret = DP[cur][late][abs];
	if (ret) return ret;
	if (cur == N)
	{
		if (!late) ret++;
		if (abs < 2) ret++;
		ret++;

		return ret % DIV;
	}

	if (!late) ret += func(cur + 1, late + 1, 0) % DIV;
	if (abs < 2) ret += func(cur + 1, late, abs + 1) % DIV;
	ret += func(cur + 1, late, 0) % DIV;
	ret %= DIV;

	return ret % DIV;
}

int main()
{
	Init();

	std::cin >> N;

	std::cout << func(1, 0, 0) % DIV;
}