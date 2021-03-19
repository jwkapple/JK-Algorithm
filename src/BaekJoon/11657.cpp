#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long
#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const ll INF = 1e18;
const int MAX = 500 + 1;

std::vector<pii> adj[MAX];
ll data[MAX];
int N, M;

int main()
{
	Init();

	std::cin >> N >> M;

	bool isInf = false;
	int from, to, v;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> from >> to >> v;
		adj[from - 1].push_back(pii(to - 1, v));
	}

	std::fill(data, data + N, INF);

	data[0] = 0;
	for (int a = 0; a < N; ++a)
	{
		for (int i = 0; i < N; ++i)
		{
			for (auto p : adj[i])
			{
				auto[next, value] = p;
				if (data[i] != INF && data[next] > data[i] + value)
				{
					if (a == N - 1) { isInf = true; break; }
					else data[next] = data[i] + value;
				}
			}
		}
	}

	if (isInf) std::cout << -1;
	else
	{
		for (int i = 1; i < N; ++i)
		{
			if (data[i] == INF) std::cout << -1;
			else std::cout << data[i];
			std::cout << "\n";
		}
	}
}