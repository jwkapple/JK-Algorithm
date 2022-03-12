#include <iostream>
#include <cmath>

#define ll long long

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 1e5 + 1;

int data[MAX];
int N;

ll func(int num)
{
	ll total = 0;

	for (int i = 1; i < N; ++i)
	{
		total += std::abs(1LL * num * i - data[i]);
	}

	return total;
}

int main()
{
	Init();

	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> data[i];
	}

	int low = 0, high = data[N - 1];
	while (high - low >= 3)
	{
		int p = (low * 2 + high) / 3;
		int q = (low + high * 2) / 3;
		if (func(p) <= func(q))
			high = q;
		else
			low = p;
	}

	ll result = 1e19;
	for (int i = low; i <= high; ++i)
	{
		ll tmp = func(i);
		if (result > tmp)
			result = tmp;
	}

	std::cout << result;
}