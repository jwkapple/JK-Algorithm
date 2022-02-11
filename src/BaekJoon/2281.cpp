#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 1000 + 1;

int data[MAX], dp[MAX][MAX];
int N, M;

int func(int cur, int num)
{
	if (cur == N)
		return 0;
	auto &ret = dp[cur][num];

	if (ret)
		return ret;

	int total = M, min = 1e9, value;

	while (total >= 0 && cur != N)
	{
		if (total - data[cur] >= 0)
		{
			total -= data[cur];
			value = func(++cur, num + 1);

			value += total * total;

			min = min > value ? value : min;
			total--;
		}
		else
			break;
	}

	return ret = min;
}
int main()
{
	Init();

	std::cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> data[i];
	}

	int result = func(0, 0);

	std::cout << result << "\n";
}