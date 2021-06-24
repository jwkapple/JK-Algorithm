#include <iostream>
#include <algorithm>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 2000 + 1;

int data[MAX];
int N, result = 0;

int main()
{
	Init();

	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> data[i];
	}

	std::sort(data, data + N);

	int left, right, cur, value;
	for (int i = 0; i < N; ++i)
	{
		cur = data[i];
		left = 0, right = N - 1;

		while (left < right)
		{
			if (left == i) { left++; continue; }
			if (right == i) { right--; continue; }

			value = data[left] + data[right];
			if (value == cur) { result++; break; }

			if (value < cur) left++;
			else right--;
		}
	}

	std::cout << result;
}