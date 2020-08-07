#include <iostream>

int main()
{
	unsigned long A, B, C;

	std::cin >> A >> B >> C;

	if (B >= C) std::cout << -1;

	else
	{
		unsigned long profit = C - B;

		unsigned long minMat = A / profit;

		std::cout << minMat + 1;
	}
}

