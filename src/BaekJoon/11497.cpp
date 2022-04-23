#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 1e4 + 1;

std::vector<int> result;
int data[MAX];
int T, N;

int main()
{
	Init();

	std::cin >> T;

	while (T--)
	{
		std::priority_queue<int, std::vector<int>, std::greater<int>> Q;
		std::cin >> N;

		int tmp;
		for (int i = 0; i < N; ++i)
		{
			std::cin >> tmp;
			Q.push(tmp);
		}

		int left = 1, right = N;

		while (!Q.empty())
		{
			data[left++] = Q.top();
			Q.pop();

			if (!Q.empty())
			{
				data[right--] = Q.top();
				Q.pop();
			}
		}

		int max = 0;
		int interval;
		for (int i = 2; i <= N; ++i)
		{
			interval = std::abs(data[i] - data[i - 1]);
			max = max > interval ? max : interval;
		}

		interval = std::abs(data[N] - data[1]);
		max = max > interval ? max : interval;
		result.push_back(max);
	}

	for (auto p : result)
	{
		std::cout << p << "\n";
	}
}