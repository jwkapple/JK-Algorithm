#include <iostream>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e4 + 1;

std::vector<int> result;
int map[MAX], data[MAX];
int T, N, M;


int main()
{
	Init();

	std::cin >> T;

	while (T--)
	{
		std::cin >> N;

		for (int i = 1; i <= N; ++i)
		{
			std::cin >> map[i];
		}

		std::cin >> M;

		int value;

		data[0] = 1;

		for (int i = 1; i <= N; ++i)
		{
			for (int j = map[i]; j <= M; ++j)
			{
				data[j] += data[j - map[i]];
			}
		}

		result.push_back(data[M]);

		for (int i = 0; i <= M; ++i) { data[i] = 0; }
	}

	for (auto p : result)
	{
		std::cout << p << "\n";
	}
}