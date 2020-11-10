#include <iostream>
#include <algorithm>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

int C[51];
std::vector<int> B;

int N, M;

int main()
{
	Init();

	std::cin >> N;

	for (int i = 0;i < N; ++i)
	{
		std::cin >> C[i];
	}

	std::sort(C, C + N, [](auto& left, auto& right)
	{
		return left > right;
	});

	std::cin >> M;

	B.resize(M);

	for (int i = 0; i < M; ++i)
	{
		std::cin >> B[i];

		if (B[i] > C[0])
		{
			std::cout << -1;
			return 0;
		}
	}

	std::sort(B.begin(), B.begin() + M, [](auto left, auto right)
	{
		return left > right;
	});

	int result = 0;
	while (true)
	{
		result++;
		for (int i = 0; i < N; i++) {

			for (int j = 0; j < B.size(); j++) {
				if (C[i] >= B[j]) {
					B.erase(B.begin() + j);
					break;
				}
			}
		}

		if (B.size() == 0)
			break;
	}

	std::cout << result;
}