#include <iostream>
#include <queue>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 1e5 + 1;

std::queue<pii> Q;

bool visited[MAX][2];
int data[MAX][2];
int N, K;

int main()
{
	Init();

	std::cin >> N >> K;

	char tmp;
	for (int i = 1; i <= N; ++i)
	{
		std::cin >> tmp;
		data[i][0] = tmp - '0';
	}

	for (int i = 1; i <= N; ++i)
	{
		std::cin >> tmp;
		data[i][1] = tmp - '0';
	}

	Q.push(pii(1, 0));

	int size, cur = 0;
	while (!Q.empty())
	{
		size = Q.size();

		for (int i = 0; i < size; ++i)
		{
			auto [y, x] = Q.front();
			Q.pop();

			if (y <= cur)
				continue;

			if (visited[y][x])
				continue;

			visited[y][x] = true;

			y--;
			if (!visited[y][x] && data[y][x])
				Q.push(pii(y, x));

			y += 2;
			if (y > N)
			{
				std::cout << 1;
				return 0;
			}
			else
			{
				if (!visited[y][x] && data[y][x])
					Q.push(pii(y, x));
			}
			y += K - 1;
			x = x == 1 ? 0 : 1;
			if (y > N)
			{
				std::cout << 1;
				return 0;
			}
			else
			{
				if (!visited[y][x] && data[y][x])
					Q.push(pii(y, x));
			}
		}

		cur++;
	}

	std::cout << 0;
}
