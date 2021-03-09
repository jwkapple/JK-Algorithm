#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

std::priority_queue<pii, std::vector<pii>, std::greater<pii>> Q;
std::vector<pii> data;
std::vector<pii> reverse;
int N, L, result = 0;

int main()
{
	Init();

	std::cin >> N;

	int from, to;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> from >> to;
		if (from > to)
		{
			data.push_back(pii(to, from));
			reverse.push_back(pii(from, to));
		}
		else
		{
			data.push_back(pii(from, to));
			reverse.push_back(pii(to, from));
		}
	}

	std::sort(data.begin(), data.end());
	std::sort(reverse.begin(), reverse.end());
	std::cin >> L;

	from = 0, to = 0;

	for (int i = 0; i < N; ++i)
	{
		auto[left, right] = data[i];

		if (!Q.empty())
		{
			while (Q.top().first < left)
			{
				Q.pop();

				if (Q.empty()) break;
			}
		}

		int end = left + L;

		while (reverse[to].first <= end && to < N)
		{
			if (reverse[to].first - reverse[to].second <= L) Q.push(pii(reverse[to].second, reverse[to].first));
			to++;

			if (to == N) break;
		}

		int size = Q.size();

		result = result > size ? result : size;

		if (to == N) break;
	}

	std::cout << result;
}