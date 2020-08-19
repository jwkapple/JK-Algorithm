#include <iostream>
#include <algorithm>

int little[9];
int N;

int main()
{
	int tmp = 0;
	for (int i = 0; i < 9; i++)
	{
		std::cin >> little[i];

		tmp += little[i];
	}

	tmp -= 100;

	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (tmp == little[i] + little[j])
			{
				little[i] = 0;
				little[j] = 0;

				break;
			}
		}
		if (little[i] == 0) break;
	}

	std::sort(little, little + 9);

	for (int i = 2; i < 9; i++)
	{
		std::cout << little[i] << "\n";
	}
}