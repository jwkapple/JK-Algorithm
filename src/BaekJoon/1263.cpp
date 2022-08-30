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

std::priority_queue<pii> Q;
int N;

int main()
{
	Init();

	std::cin >> N;

	int T, S;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> T >> S;

		Q.push(pii(S, T));
	}

	int current = 1e6 + 1;
	while (!Q.empty())
	{
		auto [dead, time] = Q.top();
		Q.pop();

		if (current >= dead)
			current = dead;

		current -= time;
	}

	if (current < 0)
		std::cout << -1;
	else
		std::cout << current;
}
