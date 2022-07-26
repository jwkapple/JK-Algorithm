#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 3e6 + 1;

int data[MAX * 2], visited[3000 + 1];
int N, D, K, C, L, R, total = 0, max = 0, limit;

int main()
{
	Init();

	std::cin >> N >> D >> K >> C;

	L = 1, R = K, limit = K + 1;
	for (int i = 1; i <= N; ++i)
	{
		std::cin >> data[i];
		data[i + N] = data[i];
	}

	for (int i = 1; i <= K; ++i)
	{
		int cur = data[i];
		if (visited[cur] == 0)
			total++;

		visited[cur]++;
	}

	int value = total + !visited[C];
	max = max > value ? max : value;

	while (true)
	{
		// L 이동
		if (--visited[data[L++]] == 0)
			total--;

		// R 이동
		if (visited[data[++R]]++ == 0)
			total++;

		value = total + !visited[C];
		max = max > value ? max : value;

		if (L == N + 1 || max == limit)
			break;
	}

	std::cout << max;
}