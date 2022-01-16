#include <iostream>
#include <vector>
#include <queue>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

struct Node
{
	int Value;
	int Y;
	int X;

	Node(){};
	Node(int v, int y, int x) : Value(v), Y(y), X(x){};
};

bool operator<(Node L, Node R)
{
	return L.Value < R.Value;
}

const int MAX = 1500 + 1;

std::priority_queue<Node> Q;
int data[MAX][MAX];
int N;

int main()
{
	Init();

	std::cin >> N;

	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= N; ++x)
		{
			std::cin >> data[y][x];
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		Q.push(Node(data[N][i], N, i));
	}

	int cur = 0;
	while (true)
	{
		auto [v, y, x] = Q.top();
		Q.pop();

		if (++cur == N)
		{
			std::cout << v;
			return 0;
		}

		if (y == 1)
			continue;

		Q.push(Node(data[y - 1][x], y - 1, x));
	}
}