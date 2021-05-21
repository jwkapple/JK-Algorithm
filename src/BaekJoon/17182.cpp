#include <iostream>
#include <queue>
#include <vector>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

struct Node
{
	int Value;
	int Next;
	int History;

	Node(int v, int n, int h) : Next(n), Value(v), History(h) {};
};

bool operator>(Node L, Node R)
{
	return L.Value > R.Value;
}
const int MAX = 10 + 1;

std::priority_queue<Node, std::vector<Node>, std::greater<Node>> Q;
int map[MAX][MAX];
bool visited[MAX][1 << MAX];
int N, S, complete, result = 0;
int main()
{
	Init();

	std::cin >> N >> S;

	complete = (1 << N) - 1;

	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			std::cin >> map[y][x];
		}
	}

	Q.push(Node(0, S, 1 << S));

	while (!Q.empty())
	{
		auto[value, cur, history] = Q.top(); Q.pop();

		if (visited[cur][history]) continue;

		visited[cur][history] = true;

		if ((history & complete) == complete)
		{
			result = value;
			break;
		}

		for (int i = 0; i < N; ++i)
		{
			if (i == cur) continue;

			int tH = history | (1 << i);

			if (visited[i][tH]) continue;
			Q.push(Node(value + map[cur][i], i, history | 1 << i));
		}
	}

	std::cout << result;
}