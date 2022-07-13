#include <iostream>
#include <queue>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

std::priority_queue<pii> Q;

int N, max;
int main()
{
	Init();

	std::cin >> N;

	int T, S;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> T >> S;

		max = max > S ? max : S;

		Q.push(pii(S, T));
	}

	while (!Q.empty())
	{
		auto [end, time] = Q.top();
		Q.pop();

		max = max > end ? end : max;

		if (max < time)
		{
			std::cout << -1;
			return 0;
		}

		max -= time;
	}

	std::cout << max;
}