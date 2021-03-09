#include <iostream>
#include <vector>
#include <queue>

#define pii std::pair<int, int>
void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

std::priority_queue<pii, std::vector<pii>, std::greater<pii>> Q;
int N, result = 0;

int main()
{
	Init();

	std::cin >> N;

	int from, to;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> from >> to;
		Q.push(pii(from, to));
	}

	Q.push(pii(1e9 + 1, 1e9 + 1));

	from = -1e9, to = -1e9;
	while (!Q.empty())
	{
		auto[left, right] = Q.top(); Q.pop();

		if (left <= to) to = right > to ? right : to;
		else
		{
			result += to - from;
			from = left, to = right;
		}
	}

	std::cout << result;
}