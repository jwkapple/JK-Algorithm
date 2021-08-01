#include <iostream>
#include <algorithm>
#include <vector>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

std::vector<pii> data;
int R, C, N, M, max = 0;

bool cover(int num)
{
	int v = 0, n = 0;
	for (auto p : data)
	{
		auto[y, x] = p;
		if (y > num || n > N) return false;
		if (x > v)
		{
			v = x + num - 1;
			n++;
		}
	}

	if (n > N) return false;
	return true;
}
int main()
{
	Init();

	std::cin >> R >> C;

	std::cin >> N;
	std::cin >> M;

	int y, x;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> y >> x;
		data.push_back(pii(y, x));

		max = max > y ? max : y;
	}

	std::sort(data.begin(), data.end(), [](pii L, pii R) { return L.second < R.second; });

	int left = max, right = R;
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (cover(mid)) right = mid;
		else left = mid + 1;
	}

	std::cout << left;
}