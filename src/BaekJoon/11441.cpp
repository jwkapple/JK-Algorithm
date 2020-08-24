#include <iostream>

const int MAX = 1e6 + 1;

int data[MAX];
int result[MAX];
int N, M;


int main()
{
	std::cin >> N;

	data[0] = 0;

	for (int i = 1;i <= N; i++)
	{
		std::cin >> data[i];
		data[i] += data[i - 1];
	}

	std::cin >> M;

	for (int i = 0;i < M; i++)
	{
		int from, to;
		std::cin >> from >> to;

		result[i] = data[to] - data[from - 1];
	}

	for (int i = 0;i < M; i++)
	{
		std::cout << result[i] << "\n";
	}
}