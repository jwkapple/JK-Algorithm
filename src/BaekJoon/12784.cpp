#include <iostream>
#include <vector>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 1000 + 1;

std::vector<int> result;
std::vector<pii> data[MAX];
int T, N, M;

int func(int cur, int parent, int valueD)
{
	if (data[cur].size() == 1 && cur != 1)
	{
		return data[cur][0].second;
	}

	int total = 0;
	for (auto p : data[cur])
	{
		auto [next, value] = p;

		if (next == parent)
			continue;

		total += func(next, cur, value);
	}

	return total > valueD ? valueD : total;
}
int main()
{
	Init();

	std::cin >> T;

	int from, to, v;
	while (T--)
	{
		std::cin >> N >> M;

		for (int y = 1; y <= N; ++y)
		{
			data[y].clear();
		}

		for (int i = 0; i < M; ++i)
		{
			std::cin >> from >> to >> v;

			data[from].push_back(pii(to, v));
			data[to].push_back(pii(from, v));
		}

		result.push_back(func(1, 0, 1e9));
	}

	for (auto p : result)
	{
		std::cout << p << "\n";
	}
}