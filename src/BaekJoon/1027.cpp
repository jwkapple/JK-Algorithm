#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 50 + 2;
int data[MAX];
int N, result = 0;

int left(int num)
{
	int tot = 0;
	double max = 1 * 1e9;
	int h = data[num];

	for (int i = num - 1; i >= 0; --i)
	{
		double cur = (double)(data[i] - h) / (double)(i - num);

		if (cur < max)
		{
			tot++;
			max = cur;
		}
	}

	return tot;
}

int right(int num)
{
	int tot = 0;
	double max = -1 * 1e9;
	int h = data[num];

	for (int i = num + 1; i < N; ++i)
	{
		double cur = (double)(data[i] - h) / (double)(i - num);

		if (cur > max)
		{
			tot++;
			max = cur;
		}
	}

	return tot;
}
int main()
{
	Init();

	std::cin >> N;

	int tmp;
	for (int i = 0; i < N; ++i) { std::cin >> data[i]; }

	for (int i = 0;i < N; ++i)
	{
		int l = left(i), r = right(i);
		int current = l + r;
		result = result > current ? result : current;
	}

	std::cout << result;
}