#include <iostream>
#include <vector>
void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 2000 + 1;

bool visited[MAX];
std::vector<int> path[MAX];
int N, M;
bool result = false;

void BFS(int current, int value)
{
	if (visited[current])
		return;

	visited[current] = true;
	value++;

	if (value == 5)
	{
		result = true;
		return;
	}

	for (auto p : path[current])
	{
		if (visited[p])
			continue;
		BFS(p, value);
		if (result)
			return;
	}

	visited[current] = false;
}
int main()
{
	Init();

	std::cin >> N >> M;

	int a, b;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> a >> b;
		path[a].push_back(b);
		path[b].push_back(a);
	}

	for (int i = 0; i < N; ++i)
	{
		BFS(i, 0);
		if (result)
		{
			std::cout << 1;
			return 0;
		}
	}

	std::cout << 0;
}