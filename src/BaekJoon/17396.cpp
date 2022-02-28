#include <iostream>
#include <vector>
#include <queue>

#define ll long long
#define pii std::pair<ll, ll>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const ll MAX = 1e5 + 1;

std::vector<pii> data[MAX];
std::priority_queue<pii, std::vector<pii>, std::greater<pii>> Q;
bool sight[MAX];
ll dij[MAX];
ll N, M, result = 1e10 + 2;

int main()
{
	Init();

	std::cin >> N >> M;

	for (ll i = 0; i < N; ++i)
	{
		std::cin >> sight[i];
		dij[i] = 1e10 + 2;
	}

	sight[N - 1] = false;

	ll from, to, v;
	for (ll i = 0; i < M; ++i)
	{
		std::cin >> from >> to >> v;

		if (!sight[from] && !sight[to])
		{
			data[from].push_back(pii(to, v));
			data[to].push_back(pii(from, v));
		}
	}

	Q.push(pii(0, 0));

	while (!Q.empty())
	{
		auto [cur, value] = Q.top();
		Q.pop();

		if (dij[cur] <= value)
			continue;

		if (cur == N - 1)
		{
			result = value;
			break;
		}

		dij[cur] = value;

		for (auto p : data[cur])
		{
			auto [next, nValue] = p;

			nValue += value;

			if (dij[next] > nValue)
				Q.push(pii(next, nValue));
		}
	}

	if (result == 1e10 + 2)
		std::cout << -1;
	else
		std::cout << result;
}