#include <iostream>
#include <vector>
#include <climits>
#include <queue>

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 100 + 2;

struct Node
{
	int Current;
	int Cost;
	int Time;

	Node(int cur, int c, int t) : Current(cur), Cost(c), Time(t) {};
};

struct cmp
{
	bool operator ()(Node a, Node b)
	{
		return a.Time > b.Time;
	}
};
std::vector<int> result;
std::vector<Node> adj[MAX];
int data[MAX][10000 + 2];
int T, N, M, K;

int main() {

	Init();

	std::cin >> T;

	while (T--)
	{
		std::cin >> N >> M >> K;

		for (int i = 1; i <= N; ++i) adj[i].clear();

		int from, to, cost, time;
		for (int i = 0; i < K; ++i)
		{
			std::cin >> from >> to >> cost >> time;

			Node tmp(to, cost, time);
			adj[from].push_back(tmp);
		}

		for (int i = 1; i <= N; ++i)
		{
			for (int j = 0; j <= 10000 + 1; ++j)
			{
				data[i][j] = -1;
			}
		}

		data[1][0] = 0;

		std::priority_queue<Node, std::vector<Node>, cmp> pq;
		pq.push(Node(1, 0, 0));

		while (!pq.empty())
		{
			auto [cur, cost, time] = pq.top(); pq.pop();
			if (data[cur][cost] < time) continue;
			data[cur][cost] = time;

			for (int i = 0; i < adj[cur].size(); ++i)
			{
				auto [nCur, nCost, nTime] = adj[cur][i];
				int Cost = nCost + cost;
				if (Cost > M) continue;

				int& ret = data[nCur][Cost];
				int Time = nTime + time;
				if (ret == -1 || ret > Time)
				{
					ret = Time;
					pq.push(Node(nCur, Cost, Time));
				}
			}
		}

		int min = INT_MAX;
		for (int i = 0; i <= M; ++i)
		{
			if (data[N][i] != -1 && min > data[N][i]) min = data[N][i];
		}
		result.push_back(min);
	}


	for (int i = 0; i < result.size(); ++i)
	{
		if (result[i] != INT_MAX) std::cout << result[i] << "\n";
		else std::cout << "Poor KCM" << "\n";
	}
}