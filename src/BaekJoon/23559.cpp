#include <iostream>
#include <queue>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int ONE = 1000, FIVE = 4000;
std::priority_queue<int> Q;

int N, X, result = 0;

int main()
{
	Init();

	std::cin >> N >> X;

	int total = (X - ONE * N) / FIVE;

	int t, f;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> f >> t;
		result += t;
		Q.push(f - t);
	}

	while (!Q.empty() && total)
	{
		int cur = Q.top();
		Q.pop();

		if (cur <= 0)
			break;

		result += cur;
		total--;
	}

	std::cout << result;
}