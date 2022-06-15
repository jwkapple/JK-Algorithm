#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 1e5 + 1;

int data[MAX];
int N, M;

bool Calc(int value)
{
	int total = 0, ret = 1;
	for (int i = 1; i <= N; ++i)
	{
		if (total + data[i] > value)
		{
			ret++;
			total = data[i];
		}
		else
		{
			total += data[i];
		}
	}

	return ret <= M;
}

int func(int from, int to)
{
	if (from == to)
		return from;

	if (from + 1 == to)
		return Calc(from) ? from : to;

	int mid = (from + to) / 2;

	if (Calc(mid))
		return func(from, mid);
	else
		return func(mid + 1, to);
}
int main()
{
	Init();

	std::cin >> N >> M;

	int tmp, max = 0, total = 0;
	for (int i = 1; i <= N; ++i)
	{
		std::cin >> tmp;

		data[i] = tmp;
		max = max > tmp ? max : tmp;
		total += tmp;
	}

	std::cout << func(max, total);
}