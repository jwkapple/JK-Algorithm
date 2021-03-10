#include <iostream>
#include <vector>
#include <queue>

#define ll long long
#define pii std::pair<ll, ll>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
ll N, M, result = 0;

int main()
{
	Init();

	std::cin >> N >> M;

	ll from, to;
	for (ll i = 0; i < N; ++i)
	{
		std::cin >> from >> to;
		if (from > to)
		{
			pq.push(pii(to, from));
		}
	}

	pq.push(pii(1e9 + 1, 1e9 + 1));
	from = 0, to = 0;

	while (!pq.empty())
	{
		auto[left, right] = pq.top(); pq.pop();

		if (left <= to)
		{
			to = to > right ? to : right;
		}
		else
		{
			result += to - from;
			from = left, to = right;
		}
	}

	result *= 2;

	std::cout << result + M;
}