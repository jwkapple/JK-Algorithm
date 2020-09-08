#include <iostream>
#include <limits.h>

const int MAX = 101;

int data[MAX];
int max = INT_MIN;
int N, K;

int main()
{
	std::cin >> N >> K;

	int sum = 0;
	for (int i = 0; i < K - 1; i++)
	{
		std::cin >> data[i];
		sum += data[i];
	}

	for (int i = K - 1; i < N; i++)
	{
		std::cin >> data[i];

		sum += data[i];

		if (max < sum) max = sum;

		sum -= data[i - K + 1];
	}

	std::cout << max;
}