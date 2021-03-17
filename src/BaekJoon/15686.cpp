#include <iostream>
#include <vector>
#include <cmath>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 50 + 1;

std::vector<pii> house;
std::vector<pii> chicken;
std::vector<int> data;
bool visit[MAX];
int N, M, value = 0, close, result = 1e9;

int calc()
{
	int total = 0;
	for (int i = 0; i < house.size(); ++i)
	{
		auto[y, x] = house[i];
		int min = 1e9;

		for (int j = 0; j < data.size(); ++j)
		{
			auto[Y, X] = chicken[data[j]];
			int v = std::abs(Y - y) + std::abs(X - x);

			min = min > v ? v : min;
		}

		total += min;
	}

	return total;
}
void func(int current, int close)
{
	if (close == M)
	{
		int v = calc();
		result = v > result ? result : v;

		return;
	}

	for (int i = current; i < value; ++i)
	{
		if (visit[i]) continue;
		visit[i] = true;
		data.push_back(i);
		func(i, close + 1);
		visit[i] = false;
		data.pop_back();
	}
}
int main()
{
	Init();

	std::cin >> N >> M;

	int tmp;
	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= N; ++x)
		{
			std::cin >> tmp;

			switch (tmp)
			{
			case 0: break;
			case 1: house.push_back(pii(y, x)); break;
			case 2: chicken.push_back(pii(y, x));; break;
			}
		}

		value = chicken.size();
	}

	close = value - M;

	func(0, 0);

	std::cout << result;
}