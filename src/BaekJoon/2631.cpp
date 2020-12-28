#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 200 + 2;

int data[MAX];
int N, cur = 0;

int func(int left, int right, int num)
{
	if (left == right) return left;
	if (left + 1 == right)
	{
		if (data[left] > num) return left;
		else return right;
	}

	int mid = (left + right) / 2;

	if (data[mid] > num) return func(left, mid, num);
	else return func(mid + 1, right, num);
}
int main()
{
	Init();

	data[0] = -1;

	std::cin >> N;

	int tmp;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> tmp;
		if (data[cur] < tmp) data[++cur] = tmp;
		else data[func(0, cur, tmp)] = tmp;
	}

	std::cout << N - cur;
}