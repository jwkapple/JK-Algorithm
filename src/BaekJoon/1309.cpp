#include <iostream>

int N;
int left, right, empty;
int fLeft, fRight, fEmpty;

int main()
{
	std::cin >> N;

	left = right = empty = 1;

	for (int i = 0;i < N - 1; i++)
	{
		fLeft = (right + empty) % 9901;
		fRight = (left + empty) % 9901;
		fEmpty = (left + right + empty) % 9901;

		right = fRight;
		left = fLeft;
		empty = fEmpty;
	}

	std::cout << (left + right + empty) % 9901;
}