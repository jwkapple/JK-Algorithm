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

const int INF = 5e8 + 1;
const int MAX = 5000 + 1;

int dij[MAX], dijP[MAX], dijV[MAX];
std::priority_queue<pii, std::vector<pii>, std::greater<pii>> Q;
std::vector<pii> path[MAX];
int V, E, P, min, minP, minV;

void func(int &result, int *dij, int init, int end)
{
	while (!Q.empty())
		Q.pop();

	Q.push(pii(0, init));

	int value, cur;
	while (!Q.empty())
	{
		do
		{
			value = Q.top().first;
			cur = Q.top().second;

			Q.pop();
		} while (!Q.empty() && dij[cur] != INF);

		if (cur == end)
		{
			result = value;
			break;
		}

		if (init == 1 && cur == P)
			minP = value;

		dij[cur] = value;

		for (auto p : path[cur])
		{
			auto [nValue, next] = p;

			if (dij[next] == INF)
			{
				Q.push(pii(nValue + value, next));
			}
		}
	}
}

int main()
{
	Init();

	std::cin >> V >> E >> P;

	int from, to, v;
	for (int i = 0; i < E; ++i)
	{
		std::cin >> from >> to >> v;
		path[from].push_back(pii(v, to));
		path[to].push_back(pii(v, from));
	}

	for (int i = 1; i <= V; ++i)
	{
		dij[i] = dijP[i] = dijV[i] = INF;
	}

	func(min, dij, 1, V);

	if (minP == 0)
	{
		func(minP, dijP, 1, P);
	}

	func(minV, dijV, P, V);

	if (minV + minP == min)
		std::cout << "SAVE HIM";
	else
		std::cout << "GOOD BYE";
}