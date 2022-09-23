#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 1e5 + 1;

int data[MAX];
int N, L = 1, R = 1, max, min = 1e9;

int main()
{
	Init();

	std::cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		std::cin >> data[i];
		min = min < data[i] ? min : data[i];
	}

	max = -1 * 1e9;

	int total = 0;
	while (R <= N)
	{
		total += data[R];

		max = max > total ? max : total;

		if (total <= 0)
		{
			L = R + 1;
			total = 0;
		}

		R++;
	}

	std::cout << max;
}