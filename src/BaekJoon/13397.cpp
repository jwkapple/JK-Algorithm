#include <iostream>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

int N, M;
std::vector<int> data;

bool check(int mid)
{
	int maxNum = -1, minNum = 10000 + 1, cnt = 1;
	for (int i = 0; i < N; i++)
	{
		if (i == 0)
		{
			minNum = data[i];
			maxNum = data[i];
		}
		if (data[i] < minNum)
			minNum = data[i];
		if (data[i] > maxNum)
			maxNum = data[i];
		if (maxNum - minNum > mid)
		{
			cnt += 1;
			maxNum = data[i];
			minNum = data[i];
		}
	}
	if (M >= cnt)
		return true;
	else
		return false;
}

int main()
{
	Init();

	std::cin >> N >> M;
	data.resize(N);

	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		std::cin >> data[i];
		sum += data[i];
	}
	int ans = 1987654321, mid, left = 0, right = sum;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (check(mid))
		{
			right = mid - 1;
			if (mid < ans)
				ans = mid;
		}
		else
			left = mid + 1;
	}

	std::cout << ans;
}