#include <iostream>

#define ll long long

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e4 + 1;

int data[MAX];
ll N, M, mid, left = 0, right, result;

ll func(ll num)
{
	ll i, ans = 0;
	for (i = 0; i < M; ++i)
	{
		ans += num / data[i] + 1;
	}
	return ans;
}

int main()
{
	Init();

	std::cin >> N >> M;

	if (N <= M) { std::cout << N; return 0; }

	right = N * 50;

	for (int i = 0; i < M; ++i)
	{
		std::cin >> data[i];
	}

	while (left <= right)
	{
		mid = (left + right) / 2;
		if (func(mid) < N && N <= func(mid + 1)) break;
		else if (func(mid) < N) left = mid + 1;
		else right = mid - 1;
	}

	int i;
	result = func(mid);
	for (i = 0; i < M; ++i)
	{
		result += (mid + 1) / data[i] - mid / data[i];
		if (result >= N) break;
	}

	std::cout << i + 1;

