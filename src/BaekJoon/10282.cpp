#include <iostream>
#include <vector>
#include <queue>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 1e5 + 1;

bool visited[MAX];
std::vector<pii> result;
int T, N, D, C;

int main()
{
	Init();

	std::cin >> T;

	int A, B, S;
	while (T--)
	{
		for (int i = 1; i <= N; ++i)
		{
			visited[i] = false;
		}

		std::vector<pii> data[MAX];
		std::priority_queue<pii, std::vector<pii>, std::greater<pii>> Q;
		int total = 0, max = 0;

		std::cin >> N >> D >> C;

		for (int i = 0; i < D; ++i)
		{
			std::cin >> A >> B >> S;
			data[B].push_back(pii(S, A));
		}

		Q.push(pii(0, C));

		while (!Q.empty())
		{
			auto [time, current] = Q.top();
			Q.pop();

			if (visited[current])
				continue;

			visited[current] = true;
			total++;
			max = max > time ? max : time;

			for (auto p : data[current])
			{
				auto [nT, next] = p;

				if (visited[next])
					continue;

				Q.push(pii(nT + time, next));
			}
		}

		result.push_back(pii(total, max));
	}

	for (auto p : result)
	{
		std::cout << p.first << " " << p.second << "\n";
	}
}