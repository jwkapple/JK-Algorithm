#include <iostream>
#include <vector>

#define ll long long

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const ll MAX = 1 << 20;
const ll DIV = 1e9 + 7;

std::vector<ll> result;
bool visited[MAX * 2];
int arr[MAX], data[MAX * 2];
int N, M, K;

void update(int cur, int num)
{
	arr[cur] = num;

	ll current = MAX + cur;

	data[current] = num;

	while (current > 1)
	{
		current /= 2;

		visited[current] = true;

		ll L = visited[current * 2] ? data[current * 2] % DIV : 1;
		ll R = visited[current * 2 + 1] ? data[current * 2 + 1] % DIV : 1;

		data[current] = L * R % DIV;
	}

}

ll find(int L, int R, int from, int to, int cur)
{
	if (!visited[cur]) return 1;
	if (L > to || R < from) return 1;

	if (from <= L && to >= R) return data[cur];
	if (cur >= MAX) return data[cur];

	ll mid = (L + R) / 2;

	return (find(L, mid, from, to, cur * 2) % DIV) * (find(mid + 1, R, from, to, cur * 2 + 1) % DIV) % DIV;
}

int main()
{
	Init();

	std::cin >> N >> M >> K;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> data[MAX + i];
		visited[MAX + i] = true;
	}

	for (int i = 0; i < N; ++i)
	{
		update(i, data[MAX + i]);
	}

	int a, b, c;
	for (int i = 0; i < M + K; ++i)
	{
		std::cin >> a >> b >> c;

		switch (a)
		{
		case 1: update(b - 1, c); break;
		case 2: result.push_back(find(1, MAX, b, c, 1)); break;
		}
	}

	for (int i = 0; i < result.size(); ++i)
	{
		std::cout << result[i] << "\n";
	}
}