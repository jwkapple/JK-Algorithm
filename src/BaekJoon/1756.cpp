#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 3e5 + 1;

int data[MAX];
int D, N, cur;

int func(int from, int to, int num)
{
	if (from == to) return from;
	if (from + 1 == to)
	{
		if (data[to] < num) return from;
		else return to;
	}

	int mid = (from + to) / 2;

	if (data[mid] < num) return func(from, mid - 1, num);
	else return func(mid, to, num);
}

int main()
{
	Init();

	std::cin >> D >> N;

	data[0] = 1e9;

	int tmp;
	for (int i = 1; i <= D; ++i)
	{
		std::cin >> tmp;

		if (data[i - 1] >= tmp) data[i] = tmp;
		else data[i] = data[i - 1];
	}

	cur = D;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> tmp;
		cur = func(0, cur, tmp);

		data[cur] = tmp;

		if (cur == 0) break;

		cur--;
	}

	if (cur == 0) std::cout << 0;
	else std::cout << cur + 1;
}