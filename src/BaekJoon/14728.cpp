#include <iostream>
#include <algorithm>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

int N, T;
int data[101][100001];

pii cls[101]; // <time, value>

int func(int cur, int time)
{
	if (cls[cur].first > time) return data[cur - 1][time];
	else return std::max(cls[cur].second + data[cur - 1][time - cls[cur].first], data[cur - 1][time]);
}

int main()
{
	Init();

	std::cin >> N >> T;

	int t, v;
	for (int i = 1; i <= N; ++i)
	{
		std::cin >> cls[i].first >> cls[i].second;
	}

	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= T; ++x)
		{
			data[y][x] = func(y, x);
		}
	}

	std::cout << data[N][T];
}