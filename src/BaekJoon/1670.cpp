#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const long long DIV = 987654321;
const long long MAX = 5000 + 1;

long long DP[MAX];
long long N;

long long func(long long num)
{
	long long tot = 0;
	auto& ret = DP[num];
	if (ret) return ret;

	for (long long i = 0; i < num; ++i)
	{
		tot += (func(i) * func(num - 1 - i)) % DIV;
		tot %= DIV;
	}

	return ret = tot % DIV;
}
int main()
{
	Init();

	DP[0] = 1;
	DP[1] = 1;
	DP[2] = 2;

	std::cin >> N;

	N /= 2;

	std::cout << func(N);
}