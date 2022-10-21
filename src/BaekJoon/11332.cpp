#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#define ll unsigned long long
void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const unsigned int MAX = 1e8;

std::vector<bool> result;
int C;

int main()
{
	Init();

	std::cin >> C;
	std::cin.get();
	char tmp[100];
	unsigned int N, T, L;
	for (int i = 0; i < C; ++i)
	{
		std::cin.get(tmp, 100, ' ');

		std::cin >> N >> T >> L;

		ll value = 0;
		ll curMax = MAX * L;

		if (tmp[2] == 'N')
		{
			if (tmp[3] == '^') // N^3
			{
				value = tmp[4] == '2' ? N * N : N * N * N;
				value *= T;

				result.push_back(value <= curMax);
			}
			else if (tmp[3] == ')') // N
			{
				value = N * T;
				result.push_back(value <= curMax);
			}
			else // tmp[3] == '!'
			{
				value = T;

				while (N)
				{
					value *= N--;
					if (value > curMax)
					{
						result.push_back(false);
						break;
					}
				}

				if (N == 0)
					result.push_back(true);
			}
		}
		else // 2^N
		{
			if (N > 30)
				result.push_back(false);
			else
			{
				value = std::pow(2, N) * T;
				result.push_back(value <= curMax);
			}
		}

		std::cin.get();
		std::cin.clear();
	}

	for (auto p : result)
	{
		if (p)
			std::cout << "May Pass.\n";
		else
			std::cout << "TLE!\n";
	}
}