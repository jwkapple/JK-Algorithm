#include <iostream>
#include <vector>

#define ll long long
void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e6 * 4 + 4;

std::vector<ll> result;
ll arr[MAX];
ll seg[MAX];
int N, Q;

ll init(int from, int to, int cur)
{
	if (from == to) return seg[cur] = arr[from];

	int mid = (from + to) / 2;

	return seg[cur] = init(from, mid, cur * 2) + init(mid + 1, to, cur * 2 + 1);
}

ll sum(int from, int to, int l, int r, int cur)
{
	if (r < from || to < l) return 0;
	if (l <= from && r >= to) return seg[cur];

	int mid = (from + to) / 2;

	return sum(from, mid, l, r, cur * 2) + sum(mid + 1, to, l, r, cur * 2 + 1);
}

void update(int from, int to, int cur, int a, int b)
{
	if (a < from || a > to) return;

	seg[cur] += b;

	if (from == to && from == a) { seg[cur] = b; return; }
	int mid = (from + to) / 2;

	update(from, mid, cur * 2, a, b);
	update(mid + 1, to, cur * 2 + 1, a, b);
	seg[cur] = seg[cur * 2] + seg[cur * 2 + 1];
}
int main()
{
	Init();

	std::cin >> N >> Q;

	ll tmp;
	for (int i = 1;i <= N; ++i)
	{
		std::cin >> arr[i];
	}

	init(1, N, 1);

	ll x, y, a, b;
	for (int i = 0; i < Q; ++i)
	{
		std::cin >> x >> y >> a >> b;

		if (x > y) result.push_back(sum(1, N, y, x, 1));
		else result.push_back(sum(1, N, x, y, 1));


		arr[a] = b;

		update(1, N, 1, a, b);
	}

	for (int i = 0; i < result.size(); ++i)
	{
		std::cout << result[i] << "\n";
	}
}