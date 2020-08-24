#include <iostream>

const int MAX = 1e5 + 1;
int N, M;

int data[MAX];
int preFix[MAX] = { 0 };
int result[MAX];

int main()
{
	std::cin >> N >> M;

	for (int i = 0;i < N; i++)
	{
		std::cin >> data[i];
		preFix[i + 1] = preFix[i] + data[i];
	}

	for (int i = 0; i < M; i++)
	{
		int from, to;

		std::cin >> from >> to;

		result[i] = preFix[to] - preFix[from - 1];
	}

	for (int i = 0;i < M; i++)
	{
		std::cout << result[i] << "\n";
	}
}