#include <iostream>
#include <queue>

const int MAX = 1e5 + 1;
std::queue<int> q;
bool visited[MAX];
int second = 0;
int N, K;

void bfs()
{
	while (!q.empty())
	{
		int size = q.size();

		for (int i = 0;i < size; i++)
		{
			int current = q.front();
			q.pop();

			if (current == K) return;
			if (current >= 0 && current <= 1e5)
			{
				if (!visited[current])
				{
					q.push(current - 1);
					q.push(current + 1);
					q.push(current * 2);

					visited[current] = true;
				}
			}
		}

		second++;
	}
}

int main()
{
	std::cin >> N >> K;

	q.push(N);

	bfs();

	std::cout << second;
}