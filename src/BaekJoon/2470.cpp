#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <stdlib.h>

#define ll long long

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 1e5 + 1;

std::vector<int> data;
int N;
ll left = 0, right, result = LLONG_MAX, resultL, resultR;

int main()
{
	Init();

	std::cin >> N;
	right = N - 1;

	int tmp;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> tmp;
		data.push_back(tmp);
	}

	std::sort(data.begin(), data.end());
	ll current = 0;
	while (left < right)
	{
		current = data[left] + data[right];

		int abCurrent = std::abs(current);
		if (abCurrent < result)
		{
			result = abCurrent;
			resultL = data[left];
			resultR = data[right];
		}

		if (current >= 0)
			right--;
		else
			left++;
	}

	std::cout << resultL << " " << resultR;
}