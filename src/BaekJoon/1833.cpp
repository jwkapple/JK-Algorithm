#include <iostream>
#include <vector>
#include <queue>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

struct Node
{
	int Value;
	int From;
	int To;

	Node() {};
	Node(int v, int f, int t) : Value(v), From(f), To(t) {};
};

bool operator<(Node L, Node R) { return L.Value > R.Value; }

const int MAX = 200 + 1;

std::priority_queue<Node> Q;
std::vector<pii> result;
int parent[MAX];
int N, M = 0, C;

int find(int A)
{
	if (A == parent[A]) return A;

	auto& ret = parent[A];

	return ret = find(ret);
}

void merge(int A, int B)
{
	A = find(A);
	B = find(B);

	if (A < B) parent[B] = A;
	else parent[A] = B;
}

int main()
{
	Init();

	std::cin >> N;

	for (int i = 1; i <= N; ++i) { parent[i] = i; }
	int tmp;

	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= N; ++x)
		{
			std::cin >> tmp;

			if (y >= x) continue;

			if (tmp < 0)
			{
				C += tmp * (-1);
				merge(y, x);
			}
			else Q.push(Node(tmp, y, x));
		}
	}

	while (!Q.empty())
	{
		auto[v, from, to] = Q.top(); Q.pop();

		if (find(from) == find(to)) continue;
		else
		{
			M++;
			C += v;
			result.push_back(pii(from, to));
			merge(from, to);
		}
	}

	std::cout << C << " " << M << "\n";
	for (auto p : result)
	{
		std::cout << p.first << " " << p.second << "\n";
	}
}