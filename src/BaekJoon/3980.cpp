#include <iostream>
#include <vector>

#define pii std::pair<int, int>
void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 11 + 1;


std::vector<int> result;
int T;

int func(std::vector<pii> data[MAX], int num, int cur)
{
	if (num == 11) return 0;

	int max = -1;
	auto& current = data[num];

	for (auto p : current)
	{
		auto[value, pos] = p;

		if ((cur & 1 << pos) == 1 << pos) continue;

		int v = func(data, num + 1, cur | 1 << pos);
		if (v != -1) v += value;
		max = max > v ? max : v;
	}

	return max;
}
int main()
{
	Init();

	std::cin >> T;

	int tmp;
	while (T--)
	{
		std::vector<pii> data[MAX];

		for (int i = 0; i < 11; ++i)
		{
			for (int j = 0; j < 11; ++j)
			{
				std::cin >> tmp;
				if (tmp) data[i].push_back(pii(tmp, j));
			}
		}

		result.push_back(func(data, 0, 0));
	}

	for (auto p : result)
	{
		std::cout << p << "\n";
	}
}
