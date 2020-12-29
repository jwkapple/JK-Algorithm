#include <iostream>
#include <stdlib.h>
#include <climits>

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e5 + 1;
int data[MAX];

int N;

int main()
{
	Init();

	std::cin >> N;

	int from = 0, to = N - 1;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> data[i];
	}
	int result = INT_MAX;
	int left, right;
	while (from < to)
	{
		int value = data[from] + data[to];
		int current = std::abs(value);
		if (result > current)
		{
			result = current;
			left = from, right = to;
		}

		if (value < 0) from++;
		else to--;
	}

	std::cout << data[left] << " " << data[right];
}