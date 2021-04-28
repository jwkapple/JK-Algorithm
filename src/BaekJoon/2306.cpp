#include <iostream>
#include <cstring>
#include <string>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 500;

std::string data;
int DP[MAX][MAX];
int result = 0;

int func(int from, int to)
{
	if (from >= to) return 0;

	auto& ret = DP[from][to];

	if (ret != -1) return ret;


	for (int i = from; i < to; ++i)
	{
		int tmp = func(from, i) + func(i + 1, to);
		ret = ret > tmp ? ret : tmp;
	}

	if ((data[from] == 'a' && data[to] == 't') || (data[from] == 'g' && data[to] == 'c'))
	{
		int tmp2 = func(from + 1, to - 1) + 1;
		ret = ret > tmp2 ? ret : tmp2;
	}
	return ret;
}

int main()
{
	Init();

	std::cin >> data;
	int size = data.size();

	std::memset(DP, -1, sizeof(DP));

	result = func(0, size - 1);

	std::cout << result * 2 << "\n";
}