#include <iostream>
#include <vector>
#include <queue>

class Tree
{
public:
	std::vector<int> parents;
	std::vector<std::vector<int>> children;
	int N;

	Tree() : N(0) {}
	Tree(int n) : N(n)
	{
		parents.resize(N, -1);
		children.resize(N);
	}

	void print()
	{
		for (int i = 2; i < parents.size(); i++)
		{
			std::cout << parents[i] << "\n";
		}
	}
};

class Graph
{
public:
	int N;
	std::vector<std::vector<int>> adj;

	Graph() : N(0) {}
	Graph(int n) : N(n + 1) { adj.resize(n + 1); }

	void add(int from, int to)
	{
		adj[from].push_back(to);
		adj[to].push_back(from);
	}

	Tree makeTree(int root)
	{
		Tree T(N);
		std::queue<int> Q;

		std::vector<bool> visited;

		visited.resize(N);

		visited[root] = true;

		Q.push(root);

		while (!Q.empty())
		{
			int current = Q.front();
			Q.pop();

			for (int i = 0; i < adj[current].size(); i++)
			{
				if (!visited[adj[current][i]])
				{
					visited[adj[current][i]] = true;
					Q.push(adj[current][i]);
					T.parents[adj[current][i]] = current;
					T.children[current].push_back(adj[current][i]);
				}
			}
		}
		return T;
	}
};
int main()
{
	int tmp;
	std::cin >> tmp;

	Graph G(tmp);

	for (int i = 0; i < tmp - 1; i++)
	{
		int A, B;

		std::cin >> A >> B;

		G.add(A, B);
	}

	Tree T = G.makeTree(1);

	T.print();
}