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

std::vector<ll> data;
int N, M;

bool calc(ll max)
{
	ll remain = M;

	for (int i = 0; i < N; ++i)
	{
		ll value = max / data[i];
		remain -= value;
		if (remain <= 0)
			return true;
	}

	return false;
}

ll func(ll left, ll right)
{
	if (left == right)
		return left;
	if (left + 1 == right)
	{
		return calc(left) ? left : right;
	}

	ll mid = (left + right) / 2;

	if (calc(mid))
		return func(left, mid);
	else
		return func(mid + 1, right);
}
int main()
{
	Init();
	std::cin >> N >> M;

	int tmp;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> tmp;
		data.push_back(tmp);
	}

	std::sort(data.begin(), data.end());

	ll tmp2 = data[data.size() - 1] * M;

	std::cout << func(0, tmp2);
}