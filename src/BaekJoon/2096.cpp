#include <iostream>
#include <algorithm>
#include <climits>

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

int prevMax[5], prevMin[5];
int	current[5], tmp[5];

int N;

void findMax()
{
	for (int i = 1; i <= 3; i++) { tmp[i] = std::max(std::max(prevMax[i - 1], prevMax[i]), prevMax[i + 1]) + current[i]; }
	for (int i = 1; i <= 3; i++) { prevMax[i] = tmp[i]; }
}

void findMin()
{
	for (int i = 1; i <= 3; i++) { tmp[i] = std::min(std::min(prevMin[i - 1], prevMin[i]), prevMin[i + 1]) + current[i]; }
	for (int i = 1; i <= 3; i++) { prevMin[i] = tmp[i]; }
}

int main()
{
	Init();

	std::cin >> N;

	prevMin[0] = INT_MAX; prevMin[4] = INT_MAX;
	prevMax[0] = INT_MIN; prevMax[4] = INT_MIN;

	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			std::cin >> current[j];
		}

		findMax();
		findMin();
	}

	std::sort(prevMin, prevMin + 5);
	std::sort(prevMax, prevMax + 5);

	std::cout << prevMax[4] << " " << prevMin[0];
}