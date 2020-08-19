#include <iostream>
#include <vector>
#include <queue>

const int MAX = 101;

std::queue<int> q;
std::vector<int> data[MAX];
bool isFind;
bool visited[MAX];

int result;

int N, M;
int A, B;

void bfs(int to, int cnt)
{
	int level = 0;
	while (!q.empty())
	{
		int size = q.size();
		int current;
		for (int i = 0; i < size; i++)
		{
			current = q.front();
			if (current == to)
			{
				isFind = true;
				result = level;
				break;
			}
			q.pop();

			for (int j = 0; j < data[current].size(); j++)
			{
				if (!visited[data[current][j]])
				{
					visited[data[current][j]] = true;
					q.push(data[current][j]);
				}

			}
		}
		if (isFind) break;
		if (q.empty() && !isFind)
		{
			result = -1;
			break;
		}

		level++;
	}
}
int main()
{
	std::cin >> N;

	std::cin >> A >> B;

	std::cin >> M;

	for (int i = 0;i < M; i++)
	{
		int from, to;

		std::cin >> from >> to;

		data[from].push_back(to);
		data[to].push_back(from);
	}

	q.push(A);
	visited[A] = true;
	bfs(B, 0);

	std::cout << result;
}