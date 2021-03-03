#include <iostream>
#include <climits>
#include <vector>
#include <queue>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e3 + 1;

int N, M;

std::priority_queue<pii, std::vector<pii>, std::greater<pii>> Q;
std::vector<pii> data[MAX];
int visited[MAX];
int dij[MAX];

int main() {

	Init();

	std::cin >> N >> M;

	int from, to, v;
	for (int i = 1; i <= M; ++i)
	{
		std::cin >> from >> to >> v;

		data[from].push_back(pii(to, v));
		data[to].push_back(pii(from, v));
	}

	for (int i = 1; i <= N; ++i) dij[i] = INT_MAX;

	dij[1] = 0;
	Q.push(pii(1, 0));
	int value = 0;
	while (!Q.empty())
	{
		auto[to, value] = Q.top(); Q.pop();

		for (int i = 0; i < data[to].size(); ++i)
		{
			auto[next, nValue] = data[to][i];
			nValue += value;

			if (dij[next] > nValue)
			{
				Q.push(pii(next, nValue));
				visited[next] = to;
				dij[next] = nValue;
			}
		}
	}

	std::cout << N - 1 << "\n";

	for (int i = 2; i <= N; ++i)
	{
		std::cout << i << " " << visited[i] << "\n";
	}
}