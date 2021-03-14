#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}



const int MAX = 100 + 1;
int parent[MAX];
class Edge
{
public:
	int from;
	int to;
	double distance;

	Edge(int a, int b, double distance)
	{
		this->from = a;
		this->to = b;
		this->distance = distance;
	}

	bool operator <(Edge& edge)
	{
		return this->distance < edge.distance;
	}
};

int getParent(int x)
{
	if (parent[x] == x) return x;
	return getParent(parent[x]);
}

void unionParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int find(int a, int b)
{
	a = getParent(a);
	b = getParent(b);

	if (a == b) return 1;
	else return 0;
}


pii data[MAX];
std::vector<Edge> Data;

int N, total = 0;
double result = 0.00;

double func(int A, int B)
{
	auto [xA, yA] = data[A];
	auto [xB, yB] = data[B];

	return(std::sqrt((xA - xB) * (xA - xB) + (yA - yB) * (yA - yB)));
}

int main()
{
	Init();

	std::cin >> N;

	for (int i = 0; i < N; ++i) { parent[i] = i; }

	double x, y;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> x >> y;

		data[i] = pii(x, y);
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = i + 1; j < N; ++j)
		{
			Data.push_back(Edge(i, j, func(i, j)));
		}
	}

	std::sort(Data.begin(), Data.end());

	for (auto p : Data)
	{
		auto [from, to, value] = p;

		if (find(getParent(from), getParent(to))) continue;

		unionParent(from, to);
		result += value;
	}
	std::cout << std::fixed;
	std::cout.precision(2);
	std::cout << result;
}