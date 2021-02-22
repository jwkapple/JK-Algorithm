#include <iostream>
#include <queue>
#include <vector>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e5 + 2;
std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
std::priority_queue<int, std::vector<int>, std::greater<int>> result;
int data[MAX];
int num[MAX * 5];
int N, cur = 0;
bool visited[MAX];

int find(int from, int to, int n)
{
	if (from == to) return from;
	if (from + 1 == to)
	{
		if (data[from] < n) return to;
		else return from;
	}

	int mid = (from + to) / 2;
	if (data[mid] > n) return find(from, mid, n);
	else return find(mid + 1, to, n);
}
int main()
{
	Init();

	data[0] = -1;

	std::cin >> N;

	int a, b;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> a >> b;
		pq.push(pii(a, b));
	}

	int now = 0;
	while (!pq.empty())
	{
		auto[from, to] = pq.top(); pq.pop();
		now = from > now ? from : now;
		if (to > data[cur])
		{
			data[++cur] = to;
			num[from] = cur;
		}
		else
		{
			int tmp = find(0, cur, to);
			data[tmp] = to;
			num[from] = tmp;
		}
	}

	std::cout << N - cur << "\n";

	for (int i = now; i >= 0; --i)
	{
		if (!num[i]) continue;
		if (num[i] == cur)
		{
			cur--;
			continue;
		}

		result.push(i);
	}

	while (!result.empty())
	{
		std::cout << result.top() << "\n"; result.pop();
	}
}