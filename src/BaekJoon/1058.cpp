#include <iostream>
#include <string>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 100 + 1;

int value[MAX];
bool data[MAX][MAX];
int N, result = 0;

int main()
{
	Init();

	std::cin >> N;

	std::string tmp;

	for (int i = 1; i <= N; ++i)
	{
		std::cin >> tmp;

		for (int a = 0; a < N; ++a)
		{
			data[i][a + 1] = (tmp[a] == 'Y');
		}
	}

	for (int i = 1; i <= N; ++i)
	{

		for (int y = i + 1; y <= N; ++y)
		{
			if (data[i][y])
			{
				value[i]++;
				value[y]++;
				continue;
			}

			for (int x = 1; x <= N; ++x)
			{
				if (data[i][x] == data[y][x] && data[i][x])
				{
					value[i]++;
					value[y]++;
					break;
				}
			}
		}

		result = result > value[i] ? result : value[i];
	}

	std::cout << result;
}