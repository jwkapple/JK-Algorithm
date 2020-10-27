#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>

#define mkp std::make_pair

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

class Edge
{
public:
	int node[2];
	int value;

	Edge(int a, int b, int value)
	{
		this->node[0] = a;
		this->node[1] = b;
		this->value = value;
	}

	bool operator <(Edge& edge)
	{
		return this->value < edge.value;
	}
};

int getParent(int set[], int x)
{
	if (set[x] == x) return x;
	return set[x] = getParent(set, set[x]);
}

void unionParent(int set[], int a, int b)
{
	a = getParent(set, a);
	b = getParent(set, b);

	if (a < b) set[b] = a;
	else set[a] = b;
}

bool find(int set[], int a, int b)
{
	a = getParent(set, a);
	b = getParent(set, b);

	if (a == b) return true;
	else return false;
}

const int MAX = 1e5 + 1;

std::vector<Edge> data;
int parent[MAX];
std::pair<int, int> X[MAX], Y[MAX], Z[MAX]; // <location, sequence>
int N, result = 0;

inline void init(std::pair<int, int> set[])
{
	std::sort(set + 1, set + N + 1);
	for (int i = 1; i < N; i++)
	{
		data.push_back(Edge(set[i].second, set[i + 1].second, std::abs(set[i].first - set[i + 1].first)));
	}
}

int main()
{
	Init();

	std::cin >> N;

	int x, y, z;
	for (int i = 1; i <= N; ++i)
	{
		std::cin >> x >> y >> z;

		X[i] = mkp(x, i);
		Y[i] = mkp(y, i);
		Z[i] = mkp(z, i);
	}

	init(X); init(Y); init(Z);

	for (int i = 1; i <= N; ++i) { parent[i] = i; }

	std::sort(data.begin(), data.end());

	for (int i = 0; i < data.size(); ++i)
	{
		if (!find(parent, data[i].node[0], data[i].node[1]))
		{
			unionParent(parent, data[i].node[0], data[i].node[1]);
			result += data[i].value;
		}
	}

	std::cout << result;
}