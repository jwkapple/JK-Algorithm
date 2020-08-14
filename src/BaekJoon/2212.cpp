#include <iostream>
#include <algorithm>

const int MAX = 10001;

std::pair<int, int> interval[MAX]; // <length, interval>
int censor[MAX];
int N, K;
int result = 0;

void func()
{

}
int main()
{
	std::cin >> N >> K;

	for (int i = 0;i < N; i++)
	{
		std::cin >> censor[i];
	}

	std::sort(censor, censor + N);

	int start = censor[0], end = censor[0];

	int i = 0;
	int intervalNum = 0;
	while (true)
	{
		if (i == N) break;

		end = censor[i];

		if (start != end)
		{
			interval[intervalNum].first = end - start;
			interval[intervalNum].second = intervalNum;

			start = censor[i];
			intervalNum++;
		}

		i++;

	}

	std::sort(interval, interval + intervalNum);

	for (int j = 0; j < K - 1; j++)
	{
		interval[intervalNum - j - 1].first = 0;
	}

	for (int j = 0; j < intervalNum; j++)
	{
		if (interval[j].first != 0)
		{
			result += interval[j].first;
		}
	}

	std::cout << result;
}