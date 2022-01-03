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

const int MAX = 1000 + 1;

int N, V, E, A, B, result = 0;

std::vector<pii> path;
int dij[100 + 1];
int data[100 + 1];

void func(int num)
{
	std::priority_queue<pii, std::vector<pii>, std::greater<pii>> Q;
	Q.push(pii(num, 0));

	int cur, value;
	while (!Q.empty())
	{
		do
		{
			value = Q.top().first;
			cur = Q.top().second;
			Q.pop();
		} while (dij[cur] && !Q.empty());

		if (Q.empty())
			break;
		dij[cur] = value;

		for (auto p : path)
		{
			auto [nValue, next] = p;
			Q.push(pii(value + nValue, next));
		}
	}
}
int main()
{
	Init();

	std::cin >> N >> V >> E;
	std::cin >> A >> B;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> data[i];
	}

	int from, to, v;

	for (int i = 0; i < E; ++i)
	{
		std::cin >> from >> to >> v;
		path.push_back(pii(to, v));
		path.push_back(pii(from, v));
	}

	int tmp;
	for (int i = 0; i < N; ++i)
	{
		tmp = data[i];
		dij[tmp] = -1;
		func(tmp);

		result += dij[A] ? dij[A] : -1;
		result += dij[B] ? dij[B] : -1;
		for (int i = 1; i <= V; ++i)
		{
			dij[i] = 0;
		}
	}

	std::cout << result;
}