#include <iostream>
#include <vector>
#include <queue>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1000 + 2;

std::vector <pii> data[MAX];
bool visited[MAX];
int adj[MAX];
int N, M, X, result = 0;

int main()
{
	Init();

	std::cin >> N >> M >> X;

	int from, to, v;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> from >> to >> v;

		data[from].push_back(pii(v, to));
	}

	for (int a = 1; a <= N; ++a)
	{
		if (a == X) continue;

		int current;
		std::priority_queue<pii, std::vector<pii>, std::greater<pii> > Q;
		for (int i = 1; i <= N; ++i) { adj[i] = 1e9; visited[i] = false; }

		adj[a] = 0;

		Q.push(pii(0, a));

		while (!Q.empty())
		{
			auto[value, cur] = Q.top(); Q.pop();

			if (visited[cur]) continue;

			if (cur == X) { current = value; break; }

			adj[cur] = value;
			visited[cur] = true;

			for (int i = 0; i < data[cur].size(); ++i)
			{
				auto[nValue, nCur] = data[cur][i];

				int v = nValue + value;
				if (v < adj[nCur]) Q.push(pii(v, nCur));
			}
		}

		for (int i = 1; i <= N; ++i) { adj[i] = 1e9; visited[i] = false; }
		while (!Q.empty()) Q.pop();

		adj[X] = 0;
		Q.push(pii(0, X));

		while (!Q.empty())
		{
			auto[value, cur] = Q.top(); Q.pop();

			if (visited[cur]) continue;

			if (cur == a) { current += value; break; }

			adj[cur] = value;
			visited[cur] = true;

			for (int i = 0; i < data[cur].size(); ++i)
			{
				auto[nValue, nCur] = data[cur][i];

				int v = nValue + value;
				if (v < adj[nCur]) Q.push(pii(v, nCur));
			}
		}

		result = result > current ? result : current;
	}

	std::cout << result;
}