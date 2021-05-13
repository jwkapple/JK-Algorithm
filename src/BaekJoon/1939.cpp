#include <iostream>
#include <vector>
#include <queue>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e4 + 1;

std::vector<pii> map[MAX];
std::priority_queue<pii> Q;

int dij[MAX];
int N, M, A, B, result = 0;

int main()
{
	Init();

	std::cin >> N >> M;

	int from, to, value;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> from >> to >> value;

		map[from].push_back(pii(value, to));
		map[to].push_back(pii(value, from));
	}

	std::cin >> A >> B;

	Q.push(pii(1e9, A));

	while (!Q.empty())
	{
		auto[v, cur] = Q.top(); Q.pop();

		if (v <= dij[cur]) continue;

		if (cur == B)
		{
			result = v;
			break;
		}

		dij[cur] = v;

		for (auto p : map[cur])
		{
			auto[nValue, next] = p;

			nValue = nValue > v ? v : nValue;

			if (nValue <= dij[next]) continue;
			Q.push(pii(nValue, next));
		}
	}

	std::cout << result;
}