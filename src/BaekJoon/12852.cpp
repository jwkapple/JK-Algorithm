#include <iostream>
#include <climits>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e6 + 1;

int parent[MAX];
int DP[MAX];
int N;

int func(int num)
{
	if (!num) return 0;
	auto& ret = DP[num];

	if (ret) return ret;

	int div3 = num % 3, div2 = num % 2, minus = num - 1;

	int min;
	div3 = (!(div3) && num >= 3) ? func(num / 3) : INT_MAX;
	div2 = (!(div2) && num >= 2) ? func(num / 2) : INT_MAX;
	minus = func(minus);

	min = div3 > div2 ? div2 : div3;
	min = min > minus ? minus : min;

	if (min == div3) parent[num] = num / 3;
	if (min == div2) parent[num] = num / 2;
	if (min == minus) parent[num] = num - 1;

	return ret = min + 1;
}
int main() {

	Init();

	DP[1] = 1;
	std::cin >> N;

	int result = func(N) - 1;
	std::cout << result << "\n";

	for (int i = 0; i <= result; ++i)
	{
		std::cout << N << " ";
		N = parent[N];
	}
}