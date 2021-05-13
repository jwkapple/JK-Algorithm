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
	int Prev;
	int Cur;

	Node(int v, int p, int c) : V(v), Prev(p), Cur(c) {};
};

bool operator<(Node L, Node R) { return L.V < R.V; }

const int MAX = 1e5 + 1;

std::vector<pii> map[MAX];
std::priority_queue<Node> Q;

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

	Q.push(Node(1e9, 0, A));

	while (!Q.empty())
	{
		auto[v, prev, cur] = Q.top(); Q.pop();

		if (cur == B)
		{
			result = v;
			break;
		}
		if (v <= dij[cur]) continue;

		dij[cur] = v;

		for (auto p : map[cur])
		{
			auto[nValue, next] = p;
			if (next == prev) continue;

			nValue = nValue > v ? v : nValue;

			Q.push(Node(nValue, cur, next));
		}
	}

	std::cout << result;
}