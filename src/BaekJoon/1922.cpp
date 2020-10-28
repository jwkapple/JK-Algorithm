#include <iostream>
#include <vector>
#include <algorithm>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

int getParent(int set[], int x)
{
	if (set[x] == x) return x;
	else return set[x] = getParent(set, set[x]);
}

void unionParent(int set[], int a, int b)
{
	a = getParent(set, a);
	b = getParent(set, b);

	if (a < b) set[b] = a;
	else set[a] = b;
}

int find(int set[], int a, int b)
{
	a = getParent(set, a);
	b = getParent(set, b);

	if (a == b) return true;
	else return false;
}

class Edge
{
public:
	int node[2];
	int cost;

	Edge(int a, int b, int cost)
	{
		this->node[0] = a;
		this->node[1] = b;
		this->cost = cost;
	}

	bool operator < (Edge& edge)
	{
		return this->cost < edge.cost;
	}
};

const int MAX = 1001;

std::vector<Edge> path;
int parent[MAX];
int result = 0;
int N, M;
int main()
{
	Init();

	std::cin >> N >> M;

	int a, b, c;
	for (int i = 0; i < M; i++)
	{
		std::cin >> a >> b >> c;

		if (a == b) continue;

		path.push_back(Edge(a, b, c));
	}

	std::sort(path.begin(), path.end());

	for (int i = 1; i <= N; ++i)
	{
		parent[i] = i;
	}

	for (int i = 0; i < path.size(); ++i)
	{
		auto cur = path[i];
		if (!find(parent, cur.node[0], cur.node[1]))
		{
			unionParent(parent, cur.node[0], cur.node[1]);
			result += cur.cost;
		}
	}

	std::cout << result;
}