#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e4 + 2;

int data[MAX];
int K, N, result = 0;
int main()
{
	Init();

	std::cin >> K >> N;

	int tmp, left = 1, right = -1;
	for (int i = 0; i < K; ++i)
	{
		std::cin >> tmp;
		right = right > tmp ? right : tmp;
		data[i] = tmp;
	}

	long long cnt, mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		cnt = 0;

		for (int i = 0; i < K; ++i)
		{
			cnt += data[i] / mid;
		}

		if (cnt >= N)
		{
			left = mid + 1;
			result = mid;
		}
		else right = mid - 1;
	}

	std::cout << result;
}