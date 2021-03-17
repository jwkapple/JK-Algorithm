#include <iostream>
void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 2e5 + 1;
const int BOX = 1e5 + 1;
int data[MAX];
int stack[BOX];

int N, K, max, maxN, result = 1, left = 0, right = 0;

int calc()
{
	int max = 0;

	for (int i = 0; i < 10; ++i)
	{
		max = max > stack[i] ? max : stack[i];
	}

	return max;
}
int main()
{
	Init();

	std::cin >> N >> K;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> data[i];
	}

	stack[data[0]]++;
	max = 1;
	maxN = data[0];

	while (right != N)
	{
		int current = calc();

		if (max <= K)
		{
			result = result > right - left + 1 ? result : right - left + 1;

			right++;
			if (right == N) break;
			stack[data[right]]++;
			if (max < stack[data[right]])
			{
				max = stack[data[right]];
				maxN = data[right];
			}
			continue;
		}
		else
		{
			if (left == N) break;
			if (maxN == data[left]) max--;
			stack[data[left]]--;
			left++;
		}
	}

	std::cout << result;
}