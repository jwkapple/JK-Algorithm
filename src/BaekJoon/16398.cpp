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
	int From;
	int To;
	int V;

	Node(int f, int t, int v) : From(f), To(t), V(v) {};
};

bool operator<(const Node& R, const Node& L) { return R.V < L.V; }

const int MAX = 1e4 + 1;

std::vector<Node> data;
int parent[MAX];
int N;
long long result = 0;

int Find(int A)
{
	auto& cur = parent[A];
	if (cur == -1) return A;
	return cur = Find(parent[A]);
}

void Union(int A, int B)
{
	A = Find(A);
	B = Find(B);

	if (A == B) return;

	if (A > B) parent[A] = B;
	else parent[B] = A;
}

int main()
{
	Init();

	std::cin >> N;

	std::fill(parent + 1, parent + N + 1, -1);

	int tmp;
	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= N; ++x)
		{
			std::cin >> tmp;

			if (y == x) continue;
			data.push_back(Node(y, x, tmp));
		}
	}

	std::sort(data.begin(), data.end());

	for (int a = 0; a < data.size(); ++a)
	{
		auto[y, x, v] = data[a];

		if (Find(y) == Find(x)) continue;

		Union(y, x);
		result += v;
	}
	std::cout << result;
}