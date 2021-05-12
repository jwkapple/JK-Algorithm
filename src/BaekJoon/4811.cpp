#include <iostream>
#include <vector>

#define ll long long
void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 30 + 1;

ll DP[MAX][MAX * 2];
std::vector<ll> result;
int N;

ll func(int W, int H)
{
	if (W < 0 || H < 0) return 0;
	auto& ret = DP[W][H];

	if (W == 0 && H == 1) return ret = 1;
	if (ret) return ret;

	return ret = func(W - 1, H + 1) + func(W, H - 1);
}

int main()
{
	Init();

	while (true)
	{
		std::cin >> N;

		if (!N) break;

		result.push_back(func(N - 1, 1));
	}

	for (auto p : result) { std::cout << p << "\n"; }
}