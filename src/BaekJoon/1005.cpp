#include <iostream>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1000 + 1;

std::vector<int> parent[MAX];
std::vector<int> result;
int construct[MAX], prev[MAX];
int T, N, K, finale;

void clear()
{
	for (int i = 1; i <= N; ++i)
	{
		parent[i].clear();
		construct[i] = 0, prev[i] = 0;
	}
}
int main() {

	Init();

	std::cin >> T;

	while (T--)
	{
		std::cin >> N >> K;
		std::vector<int> value(N + 1);

		for (int i = 1; i <= N; ++i)
		{
			std::cin >> value[i];
		}

		int from, to;
		for (int i = 0; i < K; ++i)
		{
			std::cin >> from >> to;

			parent[from].push_back(to);
			prev[to]++;
		}

		std::cin >> finale;

		while (prev[finale] != -1)
		{
			for (int i = 1; i <= N; ++i)
			{
				if (prev[i] == -1) continue;
				if (!prev[i])
				{
					prev[i] = -1;
					for (int j = 0; j < parent[i].size(); ++j)
					{
						auto cur = parent[i][j];
						prev[cur]--;
						int v = value[i] + construct[i];
						construct[cur] = v > construct[cur] ? v : construct[cur];
					}
				}
			}
		}

		result.push_back(construct[finale] + value[finale]);

		clear();
	}

	for (auto p : result)
	{
		std::cout << p << "\n";
	}
}