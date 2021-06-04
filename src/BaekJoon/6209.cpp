#include <iostream>
#include <algorithm>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 5e4 + 2;

int data[MAX];
int D, M, N, result = 0;

int main()
{
	Init();

	std::cin >> D >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		std::cin >> data[i];
	}

	data[N + 1] = D;

	std::sort(data + 1, data + N + 1);

	int left = 0, right = D, mid, pos, cnt = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		pos = 0, cnt = 0;

		for (int i = 1; i <= N + 1; ++i)
		{
			if (data[i] - data[pos] < mid) cnt++;
			else pos = i;
		}

		if (cnt > M) right = mid - 1;
		else
		{
			left = mid + 1;
			result = mid;
		}
	}

	std::cout << result;
}