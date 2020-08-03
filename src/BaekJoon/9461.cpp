#include <iostream>

unsigned long func(int N, unsigned long* container)
{
	if (N == 0) return 0;
	else if (N > 0 && N <= 3) return 1;
	if (container[N] == 0)
	{
		container[N] = func(N - 2, container) + func(N - 3, container);
	}

	return container[N];
}
int main()
{
	int T;
	int N;
	std::cin >> T;

	unsigned long* result = new unsigned long[T];

	unsigned long* container = new unsigned long[101];

	container[0] = 0;
	for (int i = 1; i < 4; i++)
	{
		container[i] = 1;
	}
	for (int i = 4; i < 101; i++)
	{
		container[i] = 0;
	}
	for (int i = 0; i < T; i++)
	{
		std::cin >> N;
		result[i] = func(N, container);
	}

	for (int i = 0; i < T; i++)
	{
		std::cout << result[i] << '\n';
	}
}