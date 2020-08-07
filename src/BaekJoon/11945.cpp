#include <iostream>

#include <vector>
#include <string>
int main()
{
	int N, M;
	std::cin >> N >> M;

	std::vector<std::string> data(N);

	for (int i = 0;i < N; i++)
	{
		std::cin >> data[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			std::cout << data[i][M - j - 1];
		}

		std::cout << "\n";
	}
}
