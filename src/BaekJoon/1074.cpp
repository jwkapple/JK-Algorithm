#include <iostream>
#include <cmath>

int N, R, C;
int result = 0;

int main()
{
	std::cin >> N >> R >> C;

	while (N)
	{
		int cross = std::pow(2, N - 1);
		int X = R / cross;
		int Y = C / cross;

		result += std::pow(2, (N - 1) * 2) * (X * 2 + Y);

		R -= std::pow(2, N - 1) * X;
		C -= std::pow(2, N - 1) * Y;
		N--;
	}

	std::cout << result;
}