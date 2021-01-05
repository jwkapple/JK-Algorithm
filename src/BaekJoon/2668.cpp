#include <iostream>
#include <vector>
#include <algorithm>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 100 + 1;

std::vector<int> result;
int N;
int path[MAX];
bool visited[MAX];

void dfs(int current, int start)
{
	if (visited[current])
	{
		if (current == start) result.push_back(start);
	}
	else
	{
		visited[current] = true;
		dfs(path[current], start);
	}
}
int main()
{
	Init();

	std::cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		std::cin >> path[i];
	}

	for (int i = 1; i <= N; ++i)
	{
		std::fill(visited + 1, visited + N + 1, 0);
		dfs(i, i);
	}

	std::cout << result.size() << "\n";
	for (int i = 0; i < result.size(); ++i) { std::cout << result[i] << "\n"; }
}