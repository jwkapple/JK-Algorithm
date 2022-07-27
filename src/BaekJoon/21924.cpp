#include <iostream>
#include <queue>
#include <vector>

#define ll long long
void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

struct Node
{
	int From;
	int To;
	int Value;

	Node(){};
	Node(int f, int t, int v) : From(f), To(t), Value(v){};
};

bool operator>(const Node &L, const Node &R)
{
	return L.Value > R.Value;
}

const int MAX = 1e5 + 1;

std::priority_queue<Node, std::vector<Node>, std::greater<Node>> Q;
ll parent[MAX];
int N, M, nDone = 1;
ll origin;

int find(int A)
{
	if (parent[A] == A || parent[A] < 0)
		return A;

	return parent[A] = find(parent[A]);
}

void merge(int A, int B, int value)
{
	int pA = find(A), pB = find(B);

	if (pA < pB)
	{
		if (parent[pA] > 0)
			parent[pA] = value * -1;
		else
			parent[pA] += value * -1;

		if (parent[pB] < 0)
			parent[pA] += parent[pB];
		parent[pB] = pA;
	}
	else
	{
		if (parent[pB] > 0)
			parent[pB] = value * -1;
		else
			parent[pB] += value * -1;

		if (parent[pA] < 0)
			parent[pB] += parent[pA];
		parent[pA] = pB;
	}
}

int main()
{
	Init();

	std::cin >> N >> M;

	int f, t, v;
	for (int i = 1; i <= N; ++i)
	{
		parent[i] = i;
	}

	for (int i = 0; i < M; ++i)
	{
		std::cin >> f >> t >> v;

		Q.push(Node(f, t, v));
		origin += v;
	}

	int from, to, value;
	while (!Q.empty())
	{
		do
		{
			from = Q.top().From;
			to = Q.top().To;
			value = Q.top().Value;

			Q.pop();
		} while (parent[from] == 1 && parent[to] == 1 && !Q.empty());

		if (Q.empty())
			break;

		int fParent = find(from), tParent = find(to);

		if (fParent != tParent)
		{
			merge(fParent, tParent, value);
		}
	}

	for (int i = 2; i <= N; ++i)
	{
		if (find(i) == 1)
			nDone++;
	}

	if (nDone != N)
		std::cout << -1;
	else
		std::cout << origin + parent[1];
}