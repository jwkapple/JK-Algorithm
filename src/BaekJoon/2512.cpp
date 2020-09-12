#include <iostream>
#include <limits.h>

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e4 + 1;
int max = INT_MIN;
int result;
int N, M;
int data[MAX];

int calc(int num)
{
	unsigned long sum = 0;

	for (int i = 0;i < N; i++)
	{
		if (data[i] < num) sum += data[i];
		else sum += num;
	}
	return sum > INT_MAX ? INT_MAX : sum;
}

void func(int from, int to)
{
	if (to - from <= 1)
	{
		result = calc(to) > M ? from : to;
		return;
	}

	int middle = (from + to) / 2;

	int aver = calc(middle);
	int left = calc(from); // left가 right 보다 작은게 당연하다

	if (aver > M) func(from, middle);
	else func(middle, to);
}

int main()
{
	Init();

	std::cin >> N;

	unsigned long total = 0;
	int tmp;
	for (int i = 0; i < N; i++)
	{
		std::cin >> tmp;
		total += tmp;
		data[i] = tmp;
		if (tmp > max) max = tmp;
	}

	std::cin >> M;

	if (M >= total) std::cout << max;
	else
	{
		func(0, max);
		std::cout << result;
	}
}