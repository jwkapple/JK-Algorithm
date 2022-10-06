#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

int data[14], value[7];
int N;

void func(int from, int depth)
{
	if (depth == 7)
	{
		for (int i = 1; i <= 6; ++i)
		{
			std::cout << value[i] << " ";
		}

		std::cout << "\n";

		return;
	}

	for (int i = from; i <= N; ++i)
	{
		value[depth] = data[i];
		func(i + 1, depth + 1);
	}
}
int main()
{
	Init();

	while (std::cin >> N && N)
	{
		for (int i = 1; i <= N; ++i)
		{
			std::cin >> data[i];
		}

		func(1, 1);
		std::cout << "\n";
	}
}