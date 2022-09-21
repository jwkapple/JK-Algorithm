#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long
void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

std::vector<int> data;
int N, M;

bool calc(ll value)
{
	ll total = 0;
	for (int i = 0; i < N; ++i)
	{
		total += value / data[i];

		if (total >= M)
			return true;
	}

	return false;
}

ll func(ll L, ll R)
{
	if (L == R)
		return L;

	if (L + 1 == R)
	{
		return calc(L) ? L : R;
	}

	ll mid = (L + R) / 2;

	if (calc(mid))
		return func(L, mid);
	else
		return func(mid + 1, R);
}

int main()
{
	Init();

	std::cin >> N >> M;

	int tmp;

	data.resize(N);

	for (int i = 0; i < N; ++i)
	{
		std::cin >> data[i];
	}

	std::sort(data.begin(), data.end());

	std::cout << func(0, 1e15);
}