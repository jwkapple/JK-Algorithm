#include <iostream>
#include <string>
#include <vector>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

std::vector<pii> result;
std::string data;
int T, K;

int main()
{
	Init();

	std::cin >> T;

	while (T--)
	{
		std::vector<int> alpha[26 + 1];

		std::cin >> data;
		std::cin >> K;

		int max = -1, min = 1e9;
		int size = data.size();

		for (int i = 0; i < size; ++i)
		{
			alpha[data[i] - 'a'].push_back(i);
		}

		for (int i = 0; i < 26; ++i)
		{
			auto cur = alpha[i];
			size = cur.size();
			if (size < K)
				continue;
			for (int j = 0; j + K - 1 < size; ++j)
			{
				int interval = cur[j + K - 1] - cur[j] + 1;
				min = min > interval ? interval : min;
				max = max > interval ? max : interval;
			}
		}

		if (max == -1 || min == 1e9)
		{
			result.push_back(pii(-1, 0));
		}
		else
			result.push_back(pii(min, max));
	}

	for (auto p : result)
	{
		auto [min, max] = p;

		if (min == -1)
		{
			std::cout << -1 << "\n";
		}
		else
			std::cout << min << " " << max << "\n";
	}
}