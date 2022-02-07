#include <iostream>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 1e5 + 2;

std::vector<int> result;
bool visited[MAX];
int data[MAX];
int M, N;

int func()
{
	int total = 0;
	for (int y = 1; y <= M; ++y)
	{
		if (data[y] > data[y + 1])
		{
			total += data[y];
			visited[y] = visited[y + 1] = true;
			y++;
		}
		else
		{
			if (!visited[y - 1])
			{
				total += data[y - 1];
			}
		}
	}

	return total;
}

int main()
{
	Init();

	std::cin >> M >> N;

	bool visit[MAX];
	int value[MAX];

	while (N && M)
	{
		visited[0] = false;

		for (int y = 1; y <= M; ++y)
		{
			visited[y] = visit[0] = false;
			value[0] = 0;

			for (int x = 1; x <= N; ++x)
			{
				std::cin >> value[x];
				visit[x] = false;
			}

			value[N + 1] = 0;

			for (int x = 1; x <= N; ++x)
			{
				if (value[x] > value[x + 1])
				{
					value[0] += value[x];
					visit[x] = visit[x + 1] = true;
					x++;
				}
				else
				{
					if (!visit[x - 1])
						value[0] += value[x - 1];
				}
			}

			data[y] = value[0];
		}

		result.push_back(func());

		std::cin >> M >> N;
	}

	for (auto p : result)
	{
		std::cout << p << "\n";
	}
}