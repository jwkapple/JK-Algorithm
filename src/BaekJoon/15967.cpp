#include <iostream>
#include <vector>

#define ll long long
void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1 << 20;
std::vector<ll> result;
ll arr[MAX], data[MAX * 2], lazy[MAX * 2];
int N, M, K;

void update(int L, int R, int cur)
{
	if (!lazy[cur]) return;

	data[cur] += (R - L + 1) * lazy[cur];

	lazy[cur * 2] += lazy[cur], lazy[cur * 2 + 1] += lazy[cur];

	lazy[cur] = 0;
}

void add(int L, int R, int from, int to, int cur, int num)
{
	update(L, R, cur);

	if (cur >= MAX) { data[cur] += num; return; }
	if (to < L || from > R) return;
	if (from <= L && R <= to) { lazy[cur] += num; return; }

	int mid = (L + R) / 2;

	add(L, mid, from, to, cur * 2, num);
	add(mid + 1, R, from, to, cur * 2 + 1, num);
}

ll find(int L, int R, int from, int to, int cur)
{
	update(L, R, cur);

	if (to < L || from > R) return 0;
	if (cur >= MAX) return data[cur];

	if (from <= L && R <= to) return data[cur];

	int mid = (L + R) / 2;

	ll left = find(L, mid, from, to, cur * 2);
	ll right = find(mid + 1, R, from, to, cur * 2 + 1);

	left = left > 0 ? left : 0;
	right = right > 0 ? right : 0;

	return left + right;
}

void init(int cur, int num)
{
	int current = cur + MAX;
	data[current] += num;

	while (current > 1)
	{
		current /= 2;

		data[current] = data[current * 2] + data[current * 2 + 1];
	}
}
int main()
{
	Init();

	std::cin >> N >> M >> K;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> data[MAX + i];
		arr[i] = data[MAX + i];
	}

	for (int i = 0; i < N; ++i)
	{
		init(i, data[MAX + i]);
	}

	int a, b, c, d;
	for (int i = 0; i < M + K; ++i)
	{
		std::cin >> a;
		switch (a)
		{
		case 1:
		{
			std::cin >> b >> c;
			result.push_back(find(1, MAX, b, c, 1));
			break;
		}
		case 2:
		{
			std::cin >> b >> c >> d;
			add(1, MAX, b, c, 1, d);
			break;
		}
		}
	}

	for (int i = 0; i < result.size(); ++i)
	{
		std::cout << result[i] << "\n";
	}
}