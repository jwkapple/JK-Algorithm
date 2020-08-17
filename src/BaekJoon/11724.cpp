#include <iostream>

const int MAX = 1001;
bool data[MAX][MAX];
bool visited[MAX];
int result = 0;
int N, M;

void dfs(int num)
{
	for (int i = 1;i <= N; i++)
	{
		if (data[num][i] && !visited[i])
		{
			visited[i] = true;
			dfs(i);
		}
	}
}

void func()
{
	for (int i = 1;i <= N; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			dfs(i);
			result++;
		}
	}
}
int main()
{
	std::cin >> N >> M;

	for (int i = 0;i < M;i++)
	{
		int from, to;

		std::cin >> from >> to;

		data[from][to] = true;
		data[to][from] = true;
	}

	func();

	std::cout << result;
}