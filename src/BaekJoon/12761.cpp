#include <iostream>
#include <vector>
#include <queue>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 1e5 + 1;

std::queue<int> Q;
bool visited[MAX];

int from, to, N, M;

int main()
{
	Init();

	std::cin >> N >> M;
	std::cin >> from >> to;

	Q.push(from);

	int result = 0;

	while (!Q.empty())
	{
		int size = Q.size();

		for (int a = 0; a < size; ++a)
		{
			int value = Q.front();
			Q.pop();

			if (value >= MAX || value < 0)
				continue;
			if (visited[value])
				continue;

			if (value == to)
			{
				std::cout << result;
				return 0;
			}

			visited[value] = true;

			Q.push(value + 1);

			if (value > 0)
			{
				Q.push(value - 1);
				Q.push(value - N);
				Q.push(value - M);
			}

			if (value < to)
			{
				Q.push(value + N);
				Q.push(value + M);
				Q.push(value * M);
				Q.push(value * N);
			}
		}

		result++;
	}
}