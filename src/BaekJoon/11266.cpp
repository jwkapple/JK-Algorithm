#include <iostream>
#include <algorithm>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e4 + 1;

std::vector<int> path[MAX];
bool cutEdge[MAX];
int nodeNum[MAX];
int V, E, size = 0, current = 1;

int DFS(int num, bool isRoot)
{
	nodeNum[num] = current++;

	int value = nodeNum[num];
	int child = 0;

	for (auto p : path[num])
	{
		if (!nodeNum[p])
		{
			child++;
			int tmp = DFS(p, 0);

			if (!isRoot && tmp >= nodeNum[num])
			{
				cutEdge[num] = true;
			}
			value = std::min(value, tmp);
		}
		else value = std::min(value, nodeNum[p]);
	}

	if (isRoot && child > 1)
	{
		cutEdge[num] = true;
	}

	return value;
}
int main()
{
	Init();

	std::cin >> V >> E;

	int A, B;
	for (int i = 0; i < E; ++i)
	{
		std::cin >> A >> B;

		path[A].push_back(B);
		path[B].push_back(A);
	}

	for (int i = 1; i <= V; ++i)
	{
		if (!nodeNum[i]) DFS(i, 1);
	}

	for (int i = 1; i <= V; ++i)
	{
		if (cutEdge[i]) size++;
	}
	std::cout << size << "\n";

	for (int i = 1; i <= V; ++i)
	{
		if (cutEdge[i]) std::cout << i << " ";
	}
}