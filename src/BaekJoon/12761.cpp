#include <iostream>
#include <vector>
#include <queue>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 1e5 + 1;

std::priority_queue<pii, std::vector<pii>, std::greater<pii>> Q;
bool visited[MAX];

int from, to, N, M;

int main()
{
	Init();

	std::cin >> N >> M;
	std::cin >> from >> to;

	Q.push(pii(0, from));

	while (!Q.empty())
	{
		auto [walk, value] = Q.top();
		Q.pop();

		if (value >= MAX || value < 0)
			continue;
		if (visited[value])
			continue;
		if (value == to)
		{
			std::cout << walk;
			return 0;
		}

		visited[value] = true;

		walk++;

		Q.push(pii(walk, value + 1));

		if (value > 0)
		{
			Q.push(pii(walk, value - 1));
			Q.push(pii(walk, value - N));
			Q.push(pii(walk, value - M));
		}

		Q.push(pii(walk, value + N));
		Q.push(pii(walk, value + M));
		Q.push(pii(walk, value * M));
		Q.push(pii(walk, value * N));
	}
}