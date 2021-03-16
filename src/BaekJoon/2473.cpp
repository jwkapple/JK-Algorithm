#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

std::vector<long long> data;
long long N, from = 0, to = 1, L = 0, M = 0, R = 0;
long long min = 3e9 + 1;

long long func(long long from, long long to, long long current)
{
	if (from == to) return from;

	if (from + 1 == to)
	{
		long long F = std::abs(data[from] + current);
		long long T = std::abs(data[to] + current);

		if (F > T) return to;
		else return from;
	}

	long long mid = (from + to) / 2;

	long long L = func(from, mid, current);
	long long R = func(mid + 1, to, current);
	long long left = std::abs(data[L] + current);
	long long right = std::abs(data[R] + current);

	return left > right ? R : L;
}
int main()
{
	Init();

	std::cin >> N;

	to = N - 1;
	long long tmp;
	for (long long i = 0; i < N; ++i)
	{
		std::cin >> tmp;
		data.push_back(tmp);
	}

	std::sort(data.begin(), data.end());

	while (from + 1 < to)
	{
		long long current = data[from] + data[to];

		long long mid = func(from + 1, to - 1, current);

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