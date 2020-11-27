#include <iostream>
#include <algorithm>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 101;

int N, M, tot = 0;
int result[101][10001];
int max[MAX];
pii data[MAX];

int func(int app, int cost)
{
	if (app <= 0 || cost < 0) return 0;
	auto& ref = result[app][cost];
	if (ref) return ref;
	if (max[app] < cost) return ref = result[app][max[app]];

	if (data[app].second > cost) return ref = func(app - 1, cost);
	else return ref = std::max(data[app].first + func(app - 1, cost - data[app].second), func(app - 1, cost));
}
int main()
{
	Init();

	std::cin >> N >> M;

	for (int i = 1; i <= N; ++i) { std::cin >> data[i].first; }
	for (int i = 1; i <= N; ++i) { std::cin >> data[i].second; max[i] = max[i - 1] + data[i].second; }

	for (int y = 1; y <= N; ++y)
	{
		for (int x = 0; x <= max[y]; ++x)
		{
			result[y][x] = func(y, x);
		}
	}

	for (int i = 0; i < 10001; ++i)
	{
		if (result[N][i] >= M)
		{
			std::cout << i;

			return 0;
		}
	}
}