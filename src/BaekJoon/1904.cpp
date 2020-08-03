#include <iostream>

int main()
{
	int N;

	std::cin >> N;

	int* container = new int[1000001];

	container[0] = 0;
	container[1] = 1;
	container[2] = 2;

	for (int i = 3; i <= N; i++)
	{
		container[i] = container[i - 1] + container[i - 2];
		container[i] = container[i] % 15746;
	}

	std::cout << container[N] << "\n";
}