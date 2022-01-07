#include <iostream>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 1000 + 1;

std::vector<int> data[MAX];
int N, M;
int dp[MAX];

int func(int num)
{
	auto &ret = dp[num];

	if (ret)
		return ret;

	int tmp = 0;
	for (auto p : data[num])
	{
		tmp = func(p) + 1;
		ret = ret > tmp ? ret : tmp;
	}

	return ret;
}

int main()
{
	Init();

	std::cin >> N >> M;

	int A, B;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> A >> B;

		data[B].push_back(A);
	}

	for (int i = 1; i <= N; ++i)
	{
		std::cout << func(i) + 1 << " ";
	}
}