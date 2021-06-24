#include <iostream>
#include <algorithm>

#define ll long long
void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 2000 + 1;

ll data[MAX];
int N, result = 0;

int main()
{
	Init();

	std::cin >> N;

	if (N == 1 || N == 2)
	{
		std::cout << 0;
		return 0;
	}

	for (int i = 0; i < N; ++i)
	{
		std::cin >> data[i];
	}

	std::sort(data, data + N);


	ll left, right, cur;
	ll value;
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