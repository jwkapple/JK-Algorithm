#include <iostream>
#include <queue>
#include <vector>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 1e5 + 1;

std::priority_queue<pii, std::vector<pii>, std::greater<pii>> Q;
std::vector<pii> data[MAX];
bool visited[MAX];
int N, M, T;

int main()
{
	Init();

	std::cin >> N >> M >> T;

	int from, to, v;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> from >> to >> v;
		data[from].push_back(pii(v, to));
		data[to].push_back(pii(v, from));
	}

	Q.push(pii(0, 1));

	int cur, value, total = 0;
	while (!Q.empty())
	{
		do
		{
			value = Q.top().first;
			cur = Q.top().second;
			Q.pop();
		} while (!Q.empty() && visited[cur]);

		if (visited[cur])
			break;

		visited[cur] = true;
		total += value;

		for (auto p : data[cur])
		{
			auto [nValue, next] = p;

			if (!visited[next])
			{
				Q.push(pii(nValue, next));
			}
		}
	}

	total += ((N - 1) * (N - 2) / 2) * T;

	std::cout << total;
}