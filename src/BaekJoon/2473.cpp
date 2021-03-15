#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

std::vector<int> data;
int N, from = 0, to = 1, L = 0, M = 0, R = 0;
long long min = 3e9 + 1;

int func(int from, int to, int current)
{
	if (from == to) return from;

	if (from + 1 == to)
	{
		int F = std::abs(data[from] + current);
		int T = std::abs(data[to] + current);

		if (F > T) return to;
		else return from;
	}

	int mid = (from + to) / 2;

	int L = func(from, mid, current);
	int R = func(mid + 1, to, current);
	long long left = std::abs(data[L] + current);
	long long right = std::abs(data[R] + current);

	return left > right ? R : L;
}
int main()
{
	Init();

	std::cin >> N;

	to = N - 1;
	int tmp;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> tmp;
		data.push_back(tmp);
	}

	std::sort(data.begin(), data.end());

	while (from + 1 < to)
	{
		long long current = data[from] + data[to];

		int mid = func(from + 1, to - 1, current);

		current += data[mid];
		if (std::abs(min) > std::abs(current))
		{
			min = current;
			L = from, M = mid, R = to;
		}

		if (current < 0) from++;
		else to--;
	}

	std::cout << data[L] << " " << data[M] << " " << data[R];
}