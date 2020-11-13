#include <iostream>
#include <vector>
#include <algorithm>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

struct Road
{
	int From;
	int To;
	int Dist;

	Road() {};
	Road(int f, int t, int d) : From(f), To(t), Dist(d) {};
};

int find(int a, std::vector<int>& road)
{
	if (road[a] == a) return a;

	return road[a] = find(road[a], road);
}
bool Union(int a, int b, std::vector<int>& road)
{
	a = find(a, road);
	b = find(b, road);

	if (a == b) return false;
	else
	{
		if (a > b)  road[a] = b;
		else road[b] = a;

		return true;
	}
}

std::vector<Road> roads;
std::vector<int> result;
int N, M;

int main()
{
	Init();

	while (true)
	{
		std::cin >> N >> M;
		if (!N && !M) break;

		std::vector<int> parent;
		parent.resize(N);
		for (int i = 0;i < N; ++i) { parent[i] = i; }

		int from, to, v;
		int total = 0;
		for (int i = 0; i < M; ++i)
		{
			std::cin >> from >> to >> v;
			roads.push_back(Road(from, to, v));
			total += v;
		}

		std::sort(roads.begin(), roads.end(), [](Road& left, Road& right) {
			return left.Dist < right.Dist;
		});

		for (int i = 0; i < roads.size(); ++i)
		{
			if (Union(roads[i].From, roads[i].To, parent)) total -= roads[i].Dist;
		}

		result.push_back(total);

		roads.clear();
	}

	for (int i = 0; i < result.size(); ++i)
	{
		std::cout << result[i] << "\n";
	}
}