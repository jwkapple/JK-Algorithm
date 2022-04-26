#include <iostream>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 200 + 1;

pii data[MAX];
int DP[20 + 1][MAX];
int N, M;

int main()
{
	Init();

	std::cin >> N >> M;

	int day, page, total = 0;
	for (int i = 1; i <= M; ++i)
	{
		std::cin >> day >> page;
		data[i] = pii(day, page);

		total += day;
	}

	total = total > MAX ? MAX : total;

	for (int y = 1; y <= M; ++y)
	{
		auto [d, p] = data[y];
		for (int x = 1; x <= N; ++x)
		{
			if (x >= d)
			{
				int on = p + DP[y - 1][x - d];
				int off = DP[y - 1][x];

				DP[y][x] = on > off ? on : off;
			}
			else
			{
				DP[y][x] = DP[y - 1][x];
			}
		}
	}

	std::cout << DP[M][N];
}