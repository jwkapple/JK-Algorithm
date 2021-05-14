#include <iostream>
#include <vector>
#include <queue>
#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

struct Node
{
	int V;
	int Next;
	int Prev;

	Node(int v, int n, int p) : V(v), Next(n), Prev(p) {};
};

bool operator>(Node L, Node R) { return L.V > R.V; }

const int MAX = 1e3 + 1;

std::vector<pii> path, map[MAX];
int dij[MAX], data[MAX];
int N, M, origin = 0, result = 0;

int find()
{
	for (int i = 1; i <= N; ++i) { dij[i] = 1e9; }
	std::priority_queue<Node, std::vector<Node>, std::greater<Node>> Q;

	Q.push(Node(0, 1, 0));

	while (!Q.empty())
	{
		auto[value, cur, prev] = Q.top(); Q.pop();

		if (value >= dij[cur]) continue;

		dij[cur] = value;
		data[cur] = prev;

		if (cur == N) return dij[cur];

		for (auto p : map[cur])
		{
			auto[nValue, next] = p;

			nValue += value;

			if (nValue < dij[next]) Q.push(Node(nValue, next, cur));
		}
	}
}
int func(int from, int to)
{
	for (int i = 1; i <= N; ++i) { dij[i] = 1e9; }
	std::priority_queue<pii, std::vector<pii>, std::greater<pii>> Q;

	Q.push(pii(0, 1));

	while (!Q.empty())
	{
		auto[value, cur] = Q.top(); Q.pop();

		if (value > dij[cur]) continue;

		dij[cur] = value;

		if (cur == N) return dij[cur];

		for (auto p : map[cur])
		{
			auto[nValue, next] = p;

			nValue += value;

			if (cur == from && next == to) continue;
			if (cur == to && next == from) continue;

			if (nValue < dij[next]) Q.push(pii(nValue, next));
		}
	}

	return -1;
}
int main()
{
	Init();

	std::cin >> N >> M;

	int A, B, V;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> A >> B >> V;

		map[A].push_back(pii(V, B)), map[B].push_back(pii(V, A));
	}

	origin = find();

	int current = N;
	while (current != 1)
	{
		path.push_back(pii(current, data[current]));
		current = data[current];
	}

	for (auto p : path)
	{
		auto[from, to] = p;

		int tmp = func(from, to);
		if (tmp == -1)
		{
			std::cout << -1;
			return 0;
		}

		result = result > tmp ? result : tmp;
	}

	std::cout << result - origin;
}