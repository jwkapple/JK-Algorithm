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

	Node() {};
	Node(int v, int n, int p) : V(v), Next(n), Prev(p) {};
};

bool operator>(Node left, Node right)
{
	return left.V > right.V;
}

const int MAX = 5e4 + 1;

std::priority_queue<Node, std::vector<Node>, std::greater<Node>> Q;
std::vector<pii> path[MAX];
int dij[MAX];
int N, M, result = 0;

int main()
{
	Init();

	std::cin >> N >> M;

	int from, to, value;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> from >> to >> value;
		path[from].push_back(pii(value, to));
		path[to].push_back(pii(value, from));
	}

	for (int i = 1; i <= N; ++i) { dij[i] = 1e9; }
	Q.push(Node(0, 1, 0));

	while (!Q.empty())
	{
		auto[v, cur, prev] = Q.top(); Q.pop();

		if (cur == N) { result = v; break; }
		if (dij[cur] != 1e9) continue;

		dij[cur] = v;
		for (auto p : path[cur])
		{
			auto[nV, next] = p;

			if (next == prev) continue;

			int nValue = nV + v;
			if (nValue < dij[next]) Q.push(Node(nValue, next, cur));
		}
	}

	std::cout << result;
}