#include <iostream>
#include <vector>
typedef long long ll;

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 4e6 + 4;
enum Case { NONE = 0, UPDATE, SUM };

std::vector<ll> result;
ll arr[MAX], data[MAX], lazy[MAX];
int N, M, K;

ll init(int from, int to, int cur)
{
	if (from == to) return data[cur] = arr[from];
	int mid = (from + to) / 2;

	return data[cur] = init(from, mid, cur * 2) + init(mid + 1, to, cur * 2 + 1);
}

void propagate(int from, int to, int num)
{
	if (lazy[num])
	{
		if (from != to)
		{
			lazy[num * 2] += lazy[num];
			lazy[num * 2 + 1] += lazy[num];
		}

		data[num] += lazy[num] * (to - from + 1);
		lazy[num] = 0;
	}
}

void update(int from, int to, int num, int uFrom, int uTo, ll val)
{
	propagate(from, to, num);

	if (uFrom > to || uTo < from) return;
	if (uFrom <= from && to <= uTo)
	{
		lazy[num] = val;
		propagate(from, to, num);
		return;
	}

	ll mid = (from + to) / 2;
	update(from, mid, num * 2, uFrom, uTo, val);
	update(mid + 1, to, num * 2 + 1, uFrom, uTo, val);
	data[num] = data[num * 2] + data[num * 2 + 1];
}

ll sum(int from, int to, int num, int sFrom, int sTo)
{
	propagate(from, to, num);
	if (sFrom > to || sTo < from) return 0;
	if (sFrom <= from && sTo >= to) return data[num];

	int mid = (from + to) / 2;

	return sum(from, mid, num * 2, sFrom, sTo) + sum(mid + 1, to, num * 2 + 1, sFrom, sTo);
}

int main()
{
	Init();

	std::cin >> N >> M >> K;

	for (int i = 1;i <= N; ++i)
	{
		std::cin >> arr[i];
	}
	init(1, N, 1);

	int a, from, to;
	ll num;
	for (int i = 0; i < M + K; ++i)
	{
		std::cin >> a;

		switch (a)
		{
		case UPDATE:
		{
			std::cin >> from >> to >> num;
			update(1, N, 1, from, to, num);
			break;
		}

		case SUM:
		{
			std::cin >> from >> to;
			result.push_back(sum(1, N, 1, from, to));
			break;
		}
		}
	}

	for (int i = 0; i < result.size(); ++i) { std::cout << result[i] << "\n"; }
}