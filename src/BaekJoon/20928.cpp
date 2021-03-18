#include <iostream>
#include <algorithm>
#include <vector>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e5 + 1;

std::vector<pii> data;
bool state;
int N, M, cur = 0, current = 0, result = 0;

int main()
{
	Init();

	std::cin >> N >> M;

	data.resize(N + 1);
	for (int i = 0; i < N; ++i)
	{
		std::cin >> data[i].first;
	}

	for (int i = 0; i < N; ++i)
	{
		std::cin >> data[i].second;
		data[i].second += data[i].first;
	}

	while (data[cur].second < M)
	{
		auto[from, to] = data[cur];

		int max = to, maxN = cur;
		while (data[current].first <= to && current < N)
		{
			if (max < data[current].second)
			{
				max = data[current].second;
				maxN = current;
			}

			current++;
		}

		if (max >= M) { result++; break; }
		if (maxN == cur) { state = true; break; }

		cur = maxN;
		result++;

		if (current == N)
		{
			if (data[cur].second < M)
			{
				state = true;
				break;
			}
		}
	}

	if (state) std::cout << -1;
	else std::cout << result;
}