#include <iostream>
#include <queue>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 50 + 1;

struct Node
{
	int V;
	int F;
	int T;

	Node();
	Node(int v, int f, int t) : V(v), F(f), T(t){};
};

bool operator>(const Node &L, const Node &R)
{
	return L.V > R.V;
}

std::priority_queue<Node, std::vector<Node>, std::greater<Node>> Q;
int parent[MAX];
int N, total = 0, result = 0;

int calc(char value)
{
	if (value >= 'A' && value <= 'Z')
	{
		return value - 38;
	}
	else
		return value - 96;
}

int find(int a)
{
	auto &pA = parent[a];

	if (pA == a)
		return a;

	return pA = find(pA);
}

void merge(int a, int b)
{
	int pA = find(a);
	int pB = find(b);

	if (pA == pB)
		return;

	if (pA > pB)
	{
		parent[pA] = pB;
		find(a);
	}
	else
	{
		parent[pB] = pA;
		find(b);
	}
}

int main()
{
	Init();

	std::cin >> N;

	int cur;
	char tmp;
	for (int y = 1; y <= N; ++y)
	{
		parent[y] = y;
		for (int x = 1; x <= N; ++x)
		{
			std::cin >> tmp;
			if (tmp != '0')
			{
				cur = calc(tmp);
				total += cur;
				if (y != x)
					Q.push(Node(cur, y, x));
			}
		}
	}

	int value, from, to, fParent, tParent;
	while (!Q.empty())
	{
		do
		{
			value = Q.top().V;
			from = Q.top().F;
			to = Q.top().T;

			fParent = find(from);
			tParent = find(to);

			Q.pop();

		} while (!Q.empty() && fParent == tParent);

		if (Q.empty() && fParent == tParent)
			break;

		merge(from, to);
		result += value;
	}

	for (int i = 1; i <= N; ++i)
	{
		if (find(i) != 1)
		{
			std::cout << -1;
			return 0;
		}
	}

	std::cout << total - result;
}