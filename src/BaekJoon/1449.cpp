#include <iostream>
#include <algorithm>

const int MAX = 1001;
int data[MAX];

int N, L, result = 1;


int main()
{

	std::cin >> N >> L;

	for (int i = 0; i < N; i++)
	{
		std::cin >> data[i];
	}

	std::sort(data, data + N);

	int tmp = data[0];

	for (int i = 1; i < N;i++)
	{
		if (data[i] - tmp + 1 > L)
		{
			result++;
			tmp = data[i];
		}
	}

	std::cout << result;
}