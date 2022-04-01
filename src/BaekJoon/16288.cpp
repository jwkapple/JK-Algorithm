#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 100 + 1;

int data[MAX];
int current = 1, k, N;

int main()
{
	Init();

	std::cin >> N >> k;

	int outNum;
	for (int i = 1; i <= N; ++i)
	{
		std::cin >> outNum;

		int max = -1, maxD = -1;
		for (int j = 1; j <= k; ++j)
		{
			int cur = data[j];
			if (cur == 0 && max == -1)
			{
				max = data[j];
				maxD = j;
				break;
			}

			if (data[j] < outNum)
			{
				if (max < data[j])
				{
					max = data[j];
					maxD = j;
				}
			}
		}

		if (max == -1)
		{
			std::cout << "NO";
			return 0;
		}

		else
			data[maxD] = outNum;
	}

	std::cout << "YES";
}