#include <iostream>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 500 + 1;

std::vector<int> child[MAX], parent[MAX];
int parentN[MAX], DP[MAX], time[MAX], result[MAX];

int N, total = 0;

int main()
{
	Init();

	std::cin >> N;

	int tmp;
	for (int i = 1; i <= N; ++i)
	{
		std::cin >> time[i];

		std::cin >> tmp;
		while (tmp != -1)
		{
			parentN[i]++; parent[i].push_back(tmp);
			child[tmp].push_back(i);
			std::cin >> tmp;
		}
	}

	while (total != N)
	{
		for (int i = 1; i <= N; ++i)
		{
			if (DP[i]) continue;

			if (!parentN[i])
			{
				auto& max = DP[i];
				for (auto p : parent[i]) { max = DP[p] > max ? DP[p] : max; }
				DP[i] += time[i];

				for (auto p : child[i]) { parentN[p]--; }
				total++;
			}
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		std::cout << DP[i] << "\n";
	}
}