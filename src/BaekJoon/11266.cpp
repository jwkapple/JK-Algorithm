#include <iostream>
#include <vector>
#include <queue>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e4 + 1;

std::priority_queue<int, std::vector<int>, std::greater<int>> result;
std::vector<int> data[MAX];
int nodeNum[MAX];
int node[MAX];
int V, E, current = 1;

void DFS(int num)
{
	if (nodeNum[num]) return;
	nodeNum[num] = current++;
	node[nodeNum[num]] = num;
	auto cur = data[num];

	for (auto p : cur)
	{
		DFS(p);
	}
}

bool check(int num)
{
	for (int i = num; i <= V; ++i)
	{
		auto cur = data[node[i]];

		for (auto p : cur)
		{
			if (nodeNum[p] > num) return false;
		}
	}

	return true;
}

int main()
{
	Init();

	std::cin >> V >> E;

	int from, to;
	for (int i = 0; i < E; ++i)
	{
		std::cin >> from >> to;
		data[from].push_back(to);
		data[to].push_back(from);
	}

	DFS(1);

	if (data[1].size() >= 2) result.push(1);
	for (int i = 2; i < V; ++i)
	{
		if (check(i)) result.push(node[i]);
	}

	std::cout << result.size() << "\n";
	while (!result.empty())
	{
		std::cout << result.top() << " ";
		result.pop();
	}
}