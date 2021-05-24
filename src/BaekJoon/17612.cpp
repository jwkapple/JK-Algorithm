#include <iostream>
#include <vector>
#include <queue>

#define pii std::pair<int, int>
#define ll long long

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

struct Node
{
	int Casher;
	int ID;
	int W;

	Node(int c, int i, int w) : Casher(c), ID(i), W(w) {};
};

bool operator< (Node L, Node R) { return L.W > R.W; }

std::priority_queue<pii, std::vector<pii>, std::greater<pii>> Line;
std::priority_queue<pii> out;
std::priority_queue<Node> Q;
std::vector<pii> data;
int N, K;
ll result = 0;

int main()
{
	Init();

	std::cin >> N >> K;

	int ID, w;
	for (int i = 1; i <= N; ++i)
	{
		std::cin >> ID >> w;

		data.push_back(pii(ID, w));
	}

	for (int i = 1; i <= K; ++i) { Line.push(pii(0, i)); }

	int cur = 0;

	while (cur != N)
	{
		auto[id, w] = data[cur++];
		auto[t, cash] = Line.top(); Line.pop();

		Q.push(Node(cash, id, t + w));
		Line.push(pii(t + w, cash));
	}
	int value = 1;

	while (!Q.empty())
	{
		auto[Casher, ID, V] = Q.top(); Q.pop();

		out.push(pii(Casher, ID));

		while (!Q.empty())
		{
			if (Q.top().W == V)
			{
				auto[tCasher, tID, tV] = Q.top(); Q.pop();
				out.push(pii(tCasher, tID));
			}
			else break;
		}

		while (!out.empty())
		{
			auto[cCasher, cID] = out.top(); out.pop();
			result += (ll)value++ * (ll)cID;
		}
	}

	std::cout << result;
}