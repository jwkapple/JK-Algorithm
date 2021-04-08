#include <iostream>
#include <queue>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e5 + 1;

std::queue<int> Q;

int DP[MAX];
int N, M, result = 0, current = 0;


int main()
{
	Init();

	std::cin >> N >> M;

	for (int i = 0; i < MAX; ++i) { DP[i] = 1e9; }
	Q.push(N);

	while (!result)
	{
		int size = Q.size();

		for (int a = 0; a < size; ++a)
		{
			int cur = Q.front(); Q.pop();

			if (cur == M) { result++; continue; }
			if (DP[cur] < current) continue;
			DP[cur] = current;
			if (cur < M)
			{
				if (cur * 2 <= MAX) Q.push(cur * 2);
				if (cur + 1 <= MAX) Q.push(cur + 1);
			}

			if (cur > 0) Q.push(cur - 1);
		}

		current++;
	}

	std::cout << current - 1 << "\n";
	std::cout << result;
}