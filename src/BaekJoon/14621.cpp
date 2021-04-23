#include <iostream>
#include <vector>
#include <queue>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}


const int MAX = 10000 + 1;


std::priority_queue <pii, std::vector<pii>, std::greater<pii>> Q;
pii data[MAX];
int parent[MAX];
char map[MAX];
int N, M, result = 0;

int find(int A)
{
	auto& ret = parent[A];
	if (A == ret) return ret;
	else return ret = find(parent[A]);
}

bool merge(int A, int B)
{

	A = find(A);
	B = find(B);

	if (A == B) return false;
	else
	{
		if (A > B) parent[A] = B;
		else parent[B] = A;

		return true;
	}
}
int main()
{
	Init();

	std::cin >> N >> M;

	char tmp;
	for (int i = 1;i <= N; ++i)
	{
		std::cin >> map[i];
		parent[i] = i;
	}

	int u, v, d;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> u >> v >> d;

		if (map[u] == map[v]) continue;
		else
		{
			data[i] = pii(u, v);
			Q.push(pii(d, i));
		}
	}

	while (!Q.empty())
	{
		auto[v, info] = Q.top(); Q.pop();
		auto[from, to] = data[info];

		if (merge(from, to))
		{
			result += v;
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		if (find(parent[i]) != 1)
		{
			std::cout << -1;
			return 0;
		}
	}

	std::cout << result;
}
