#include <iostream>
#include <vector>
#include <queue>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int IMP = 1e9 + 1;
const int MAX = 1e5 + 1;

struct Node
{
	int V;
	int C;
	int M;

	Node(){};
	Node(int v, int c, int m) : V(v), C(c), M(m){};
};

bool operator>(const Node &L, const Node &R)
{
	return L.V < R.V;
}

std::priority_queue<Node, std::vector<Node>, std::greater<Node>> Q;
std::vector<pii> path[MAX];
int dij[MAX];
int N, A, B;

int main()
{
	Init();

	std::cin >> N >> A >> B;

	int from, to, v;
	for (int i = 1; i < N; ++i)
	{
		std::cin >> from >> to >> v;

		path[from].push_back(pii(v, to));
		path[to].push_back(pii(v, from));

		dij[i] = IMP;
	}

	dij[N] = IMP;
	dij[A] = 0;

	Q.push(Node(0, A, 0));

	int value, cur, max;
	while (!Q.empty())
	{
		do
		{
			cur = Q.top().C;
			value = Q.top().V;
			max = Q.top().M;

			Q.pop();
		} while (!Q.empty() && dij[cur] < value);

		if (dij[cur] < value)
			break;

		if (cur == B)
		{
			std::cout << value - max;
			return 0;
		}
		dij[cur] = value;

		for (auto p : path[cur])
		{
			auto [nValue, next] = p;

			max = max > nValue ? max : nValue;

			nValue += value;

			if (nValue < dij[next])
			{
				Q.push(Node(nValue, next, max));
			}
		}
	}
}