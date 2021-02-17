#include <iostream>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1 << 20;

std::vector<int> result;
bool visited[MAX * 2];
int arr[MAX], data[MAX * 2];
int N, M;

void update(int cur, int num)
{
	arr[cur] = num;
	int current = cur + MAX;

	while (current > 1)
	{
		current /= 2;

		visited[current] = true;

		int left = visited[current * 2] ? data[current * 2] : -1;
		int right = visited[current * 2 + 1] ? data[current * 2 + 1] : -1;

		data[current] = left > right ? left : right;
	}
}

int find(int L, int R, int from, int to, int cur)
{
	if (!visited[cur]) return 0;
	if (L > to || R < from) return 0;
	if (cur >= MAX) return data[cur];
	if (from <= L && R <= to) return data[cur];

	int mid = (L + R) / 2;

	int left = find(L, mid, from, to, cur * 2);
	int right = find(mid + 1, R, from, to, cur * 2 + 1);

	return left > right ? left : right;
}

int main()
{
	Init();

	std::cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> data[MAX + i];
		visited[MAX + i] = true;
	}

	for (int i = 0; i < N; ++i)
	{
		update(i, data[MAX + i]);
	}

	for (int i = M; i <= N - M + 1; ++i)
	{
		result.push_back(find(1, MAX, i - M + 1, i + M - 1, 1));
	}
	for (int i = 0;i < result.size(); ++i)
	{
		std::cout << result[i] << " ";
	}
}