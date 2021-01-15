#include <iostream>
#include <vector>
#include <algorithm>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

struct Node
{
	int L;
	int R;
	int V;

	Node(int l, int r, int v) : L(l), R(r), V(v) {};
};

bool operator< (const Node& L, const Node& R) { return L.V < R.V; }

const int MAX = 1000 + 1;

std::vector<Node> data;
bool daddy[MAX];
int parent[MAX];
int N, M, K, result = 0;

int Find(int x)
{
	auto& ret = parent[x];

	if (ret == x) return x;
	else return ret = Find(ret);
}

bool Union(int x, int y)
{
	x = Find(x);
	y = Find(y);

	if (y == x) return false;
	if (daddy[x]) { parent[y] = x; return true; }
	if (daddy[y]) { parent[x] = y; return true; }

	if (y > x) parent[y] = x;
	else parent[x] = y;

	return true;
}

int main()
{
	Init();

	std::cin >> N >> M >> K;

	for (int i = 1; i <= N; ++i) { parent[i] = i; }

	int tmp;
	for (int i = 0; i < K; ++i)
	{
		std::cin >> tmp;
		daddy[tmp] = tmp;
	}

	int l, r, v;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> l >> r >> v;
		data.push_back(Node(l, r, v));
	}

	std::sort(data.begin(), data.end());

	for (int i = 0; i < data.size(); ++i)
	{
		auto[y, x, v] = data[i];

		bool Y = daddy[Find(y)], X = daddy[Find(x)];

		if (Y == X && Y) continue;

		if (Union(x, y)) result += v;

	}

	std::cout << result;
}