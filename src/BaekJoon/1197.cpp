#include <iostream>
#include <algorithm>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

int getParent(int set[], int x)
{
	if (set[x] == x) return x;
	return getParent(set, set[x]);
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

	if (a == b) return 1;
	else return 0;
}

class Edge
{
public:
	int node[2];
	int distance;

	Edge(int a, int b, int distance)
	{
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}

	bool operator <(Edge& edge)
	{
		return this->distance < edge.distance;
	}
};

const int MAX = 1e4 + 1;
std::vector<Edge> data;
int parent[MAX];
int result = 0;
int V, E;
int A, B, C;

int main()
{
	Init();

	std::cin >> V >> E;

	for (int i = 0;i < E; i++)
	{
		std::cin >> A >> B >> C;
		data.push_back(Edge(A, B, C));
	}

	std::sort(data.begin(), data.end());

	for (int i = 1;i <= V; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < E; ++i)
	{
		if (!find(parent, getParent(parent, data[i].node[0]), getParent(parent, data[i].node[1])))
		{
			unionParent(parent, data[i].node[0], data[i].node[1]);
			result += data[i].distance;
		}
	}

	std::cout << result;
}