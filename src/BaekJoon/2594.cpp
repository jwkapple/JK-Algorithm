#include <iostream>
#include <vector>
#include <queue>

#define pii std::pair<int, bool>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

std::priority_queue<pii, std::vector<pii>, std::greater<pii>> Q;
int N, result = 0;

int ready(int time, bool isEnd)
{
	int hour = time / 100;
	int min = time % 100;
	min += isEnd ? 10 : -1 * 10;

	if (min >= 60)
	{
		hour++;
		min -= 60;
	}

	if (min < 0)
	{
		hour--;
		min = 60 + min;
	}

	return hour * 100 + min;
}

int func(int current, int prev)
{
	int cHour = current / 100, cMin = current % 100;
	int pHour = prev / 100, pMin = prev % 100;

	if (cMin < pMin)
	{
		cHour--;
		cMin += 60;
	}

	return (cHour - pHour) * 60 + cMin - pMin;
}

int main()
{
	Init();

	std::cin >> N;

	int prev = 1000;

	int start, end;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> start >> end;

		Q.push(pii(ready(start, false), false));
		Q.push(pii(ready(end, true), true));
	}

	int total = 0;
	while (!Q.empty())
	{
		auto [time, isEnd] = Q.top();
		Q.pop();

		if (total == 0 && !isEnd)
		{
			int cur = func(time, prev);
			result = result > cur ? result : cur;
		}

		total += isEnd ? -1 : 1;

		if (total == 0 && isEnd)
		{
			prev = time;
		}
	}

	int tmp = func(2200, prev);
	result = result > tmp ? result : tmp;

	std::cout << result;
}