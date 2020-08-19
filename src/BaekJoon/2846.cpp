#include <iostream>

int N;

int main()
{
	int current = 0;
	int prev = -1;
	int init = -1;
	int tmpResult, result = 0;

	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		std::cin >> current;
		if (prev != -1)
		{
			if (prev < current)
			{
				if (init == -1)
				{
					init = prev;
				}

				tmpResult = current - init;

				if (result < tmpResult) result = tmpResult;

				tmpResult = 0;
			}
			else
			{
				init = -1;
			}
		}

		prev = current;
	}

	std::cout << result;
}