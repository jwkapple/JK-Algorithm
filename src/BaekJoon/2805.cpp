#include <iostream>
#include <limits.h>

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e6 + 1;

int N, M;
int max = INT_MIN;
int data[MAX];
int result = 0;

int cut(int num)
{
	unsigned long res = 0;
	for (int i = 0; i < N; i++)
	{
		if (data[i] > num) res += data[i] - num;
	}

	return res > INT_MAX ? INT_MAX : res;
}

void func(int from, int to)
{
	if (to - from <= 1)
	{
		if (M > cut(to)) result = from;
		else result = to;
		return;
	}

	int middle = (from + to) / 2;
	int aver = cut(middle);
	int left = cut(to);

	if (M >= left && M < aver) func(middle, to);
	else func(from, middle);
}

int main()
{
	Init();

	std::cin >> N >> M;

	for (int i = 0;i < N; i++)
	{
		std::cin >> data[i];
		if (max < data[i]) max = data[i];
	}

	func(0, max);

	std::cout << result;
}