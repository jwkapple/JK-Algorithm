#include <iostream>
#include <queue>

#define MAX 1001

int N, E, V;
std::queue<int> table;
bool adjacent[MAX][MAX];
bool visitedDFS[MAX];
bool visitedBFS[MAX];

void DFS(int current)
{
	std::cout << current << " ";

	visitedDFS[current] = true;

	for (int i = 1;i <= N; i++)
	{
		if (adjacent[current][i] && !visitedDFS[i])
		{
			DFS(i);
		}
	}
}

void BFS(int current)
{
	table.push(current);
	visitedBFS[current] = true;

	while (!table.empty())
	{
		int tmp = table.front();

		std::cout << tmp << " ";

		table.pop();

		for (int i = 1;i <= N;i++)
		{
			if (adjacent[tmp][i] && !visitedBFS[i])
			{
				visitedBFS[i] = true;

				table.push(i);
			}
		}
	}
}
int main()
{

	std::cin >> N >> E >> V;

	int from, to;
	for (int i = 0; i < E; i++)
	{
		std::cin >> from >> to;
		adjacent[from][to] = true;
		adjacent[to][from] = true;
	}

	DFS(V);
	std::cout << "\n";
	BFS(V);
}
