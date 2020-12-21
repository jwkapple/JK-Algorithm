#include <iostream>
#include <map>

typedef long long ll;

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

std::map<int, int> m;

const int MAX = 5e5 + 1;

int arr[MAX];
int data[MAX * 4];
bool visited[MAX];
ll N, result = 0;

void update(int l, int r, int n, int idx, int val)
{
	if (idx < l || idx > r) return;

	data[n] += val;

	if (l < r)
	{
		int mid = (l + r) / 2;

		update(l, mid, n * 2, idx, val);
		update(mid + 1, r, n * 2 + 1, idx, val);
	}
}

int sum(int l, int r, int n, int sl, int sr)
{
	if (sl > r || sr < l) return 0;

	if (sl <= l && r <= sr) return data[n];

	int mid = (l + r) / 2;

	return sum(l, mid, n * 2, sl, sr) + sum(mid + 1, r, n * 2 + 1, sl, sr);
}
int main()
{
	Init();

	std::cin >> N;

	int tmp;
	for (int i = 1; i <= N; ++i)
	{
		std::cin >> tmp;
		m[tmp] = i;
	}

	for (int i = 1; i <= N; ++i)
	{
		std::cin >> tmp;
		arr[i] = m.find(tmp)->second;
	}

	for (int i = 1; i <= N; ++i)
	{
		int current = arr[i];
		visited[current] = true;

		result += sum(1, N, 1, current + 1, N);
		update(1, N, 1, current, 1);
	}

	std::cout << result;
}