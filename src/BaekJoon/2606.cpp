#include <iostream>
#include <queue>

#define MAX 101

int N, E, result;
std::queue<int> q;
bool adjacent[MAX][MAX];
bool visited[MAX];


void BFS(int start)
{
	q.push(start);

	visited[start] = true;

	while (!q.empty())
	{
		int tmp = q.front();

		q.pop();

		for (int i = 1; i <= N;i++)
		{
			if (adjacent[tmp][i] && !visited[i])
			{
				visited[i] = true;

				q.push(i);

				result++;
			}
		}
	}
}
int main()
{

	std::cin >> N;
	std::cin >> E;

	result = 0;
	int from, to;
	for (int i = 0; i < E; i++)
	{
		std::cin >> from >> to;
		adjacent[from][to] = true;
		adjacent[to][from] = true;
	}

	BFS(1);

	std::cout << result;
}
