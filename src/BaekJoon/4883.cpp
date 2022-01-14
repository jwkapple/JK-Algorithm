#include <iostream>
#include <vector>
#include <queue>

#define ll long long
#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

struct Node
{
	ll Value;
	int Y;
	int X;

	Node(){};
	Node(ll v, int y, int x) : Value(v), Y(y), X(x){};
};

bool operator>(Node L, Node R) { return L.Value > R.Value; }

const int MAX = 1e5 + 1;

std::vector<pii> path[3];
std::vector<ll> result;
int visited[MAX][4];
int data[MAX][4];
int T;

void init()
{
	path[0].push_back(pii(1, 0));
	path[0].push_back(pii(0, 1));
	path[0].push_back(pii(1, 1));
	path[1].push_back(pii(1, -1));
	path[1].push_back(pii(1, 0));
	path[1].push_back(pii(0, 1));
	path[1].push_back(pii(1, 1));
	path[2].push_back(pii(1, 0));
	path[2].push_back(pii(1, -1));
}

int main()
{
	Init();

	init();

	std::cin >> T;

	while (T)
	{

		for (int y = 1; y <= T; ++y)
		{
			for (int x = 1; x <= 3; ++x)
			{
				std::cin >> data[y][x];
				visited[y][x] = 1e9;
			}
		}

		std::priority_queue<Node, std::vector<Node>, std::greater<Node>> Q;

		Q.push(Node(data[1][2], 1, 2));

		while (!Q.empty())
		{
			auto [value, y, x] = Q.top();
			Q.pop();
			if (y == T && x == 2)
			{
				result.push_back(value);
				break;
			}

			if (visited[y][x] < value)
				continue;

			visited[y][x] = value;

			ll nValue;
			for (auto p : path[x - 1])
			{
				auto [Y, X] = p;

				Y += y;
				X += x;

				if (Y > T)
					continue;
				nValue = value + data[Y][X];

				if (visited[Y][X] <= nValue)
					continue;

				Q.push(Node(nValue, Y, X));
			}
		}

		std::cin >> T;
	}

	for (int i = 0; i < result.size(); ++i)
	{
		std::cout << i + 1 << ". " << result[i] << "\n";
	}
}