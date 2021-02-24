#include <iostream>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 2e5 + 1, MAX_D = 19;

std::vector<int> result;
int data[MAX][MAX_D];
int M, Q;

int main()
{
	Init();

	std::cin >> M;

	for (int i = 1; i <= M; ++i)
	{
		std::cin >> data[i][0];
	}

	for (int j = 1; j < MAX_D; ++j)
	{
		for (int i = 1; i <= M; ++i)
		{
			data[i][j] = data[data[i][j - 1]][j - 1];
		}
	}

	int n, x;

	std::cin >> Q;
	for (int i = 0; i < Q; ++i)
	{
		std::cin >> n >> x;

		for (int j = MAX_D - 1; j >= 0; --j)
		{
			if (n >= 1 << j)
			{
				n -= 1 << j;
				x = data[x][j];
			}
		}

		result.push_back(x);
	}

	for (auto p : result)
	{
		std::cout << p << "\n";
	}
}