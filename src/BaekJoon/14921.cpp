#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 1e5 + 1;

int data[MAX];
int N, left = 1, right, result = 2e9;

int main()
{
	Init();

	std::cin >> N;

	right = N;
	for (int i = 1; i <= N; ++i)
	{
		std::cin >> data[i];
	}

	while (left < right)
	{
		int diff = data[right] + data[left];

		if (diff > 0)
		{
			right--;
			if (result > 0)
				result = result > diff ? diff : result;
			else
			{
				int aResult = result * -1;
				if (aResult > diff)
					result = diff;
			}
		}
		else
		{
			left++;
			if (result < 0)
				result = result > diff ? result : diff;
			else
			{
				int aResult = diff * -1;
				if (aResult < result)
					result = diff;
			}
		}
	}

	std::cout << result;
}
