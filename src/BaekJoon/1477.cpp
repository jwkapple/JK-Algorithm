#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

std::priority_queue<int> Q;
std::vector<int> data;
int N, M, L;

bool calc(int value)
{
	if (value == 0)
		return false;

	int total = 0;

	for (auto p : data)
	{
		if (value >= p)
			continue;

		if (p % value == 0)
		{
			total += (p / value) - 1;
		}
		else
			total += std::floor((float)(p) / (float)(value));
	}

	return total <= M;
}

int func(int L, int R)
{
	if (L == R)
		return L;
	if (L + 1 == R)
		return calc(L) ? L : R;

	int mid = (L + R) / 2;

	return calc(mid) ? func(L, mid) : func(mid + 1, R);
}
int main()
{
	Init();

	std::cin >> N >> M >> L;

	int tmp;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> tmp;
		Q.push(tmp);
	}

	Q.push(0);

	int prev = L;
	while (!Q.empty())
	{
		int cur = Q.top();
		Q.pop();
		data.push_back(prev - cur);
		prev = cur;
	}

	std::sort(data.begin(), data.end());

	std::cout << func(0, data[data.size() - 1]);
}