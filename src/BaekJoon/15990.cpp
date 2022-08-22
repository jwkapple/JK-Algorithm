#include <iostream>
#include <vector>

#define ll long long

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int DIV = 1e9 + 9;
const int MAX = 1e5 + 1;

std::vector<int> result;
int DP[MAX];
int T;

ll func(ll value)
{
	auto &ret = DP[value];

	if (ret)
		return ret;

	if (value > 1)
	{
		ret += (1 + func(value - 1)) % DIV;

		if (value > 2)
		{
			ret += (1 + func(value - 2)) % DIV;

			if (value > 3)
			{
				ret += (1 + func(value - 3)) % DIV;
			}
		}
	}

	return ret %= DIV;
}

int main()
{
	Init();

	std::cin >> T;

	int N;

	DP[1] = 1;
	while (T--)
	{
		std::cin >> N;

		result.push_back(func(N));
	}

	for (auto p : result)
	{
		std::cout << p << "\n";
	}
}