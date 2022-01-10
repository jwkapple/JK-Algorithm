#include <iostream>
#include <queue>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

bool operator<(pii L, pii R)
{
	if (L.first != R.first)
		return L.first < R.first;
	else
		return L.second < R.second;
}

const int MAX = 1e4 + 1;

std::priority_queue<pii> Q;
bool visited[MAX];
int N, P, D, result = 0;

int main()
{
	Init();

	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> P >> D;

		Q.push(pii(P, D));
	}

	int maximum = 0, tD;

	while (!Q.empty())
	{
		auto [p, d] = Q.top();
		Q.pop();

		if (d <= maximum)
			continue;

		tD = d;
		while (tD)
		{
			if (visited[tD])
				tD--;
			else
				break;
		}

		if (tD == 0)
		{
			maximum = d;
			continue;
		}

		visited[tD] = true;
		result += p;
	}

	std::cout << result;
}