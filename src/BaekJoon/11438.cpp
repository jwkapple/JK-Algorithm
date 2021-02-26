#include <iostream>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}
//320
const int MAX = 1e5 + 1, MAX_D = 18;

std::vector<int> result;
std::vector<int> adj[MAX];
int data[MAX][MAX_D];
int depth[MAX];

int N, M;

void makeDepth(int cur)
{
	for (auto p : adj[cur])
	{
		if (depth[p] == -1)
		{
			depth[p] = depth[cur] + 1;
			data[p][0] = cur;
			makeDepth(p);
		}
	}
}

void first(int& x, int& X)
{
	for (int j = MAX_D - 1; j >= 0; --j)
	{
		if (X >= 1 << j)
		{
			X -= 1 << j;
			x = data[x][j];
		}
	}
}
int main()
{
	Init();

	std::cin >> N;

	int a, b;
	for (int i = 0; i < N - 1; ++i)
	{
		std::cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	std::fill(depth + 1, depth + N + 1, -1);
	depth[1] = 0;
	makeDepth(1);
	data[1][0] = 1;
	for (int j = 1; j < MAX_D; ++j)
	{
		for (int i = 1; i <= N; ++i)
		{
			data[i][j] = data[data[i][j - 1]][j - 1];
		}
	}

	std::cin >> M;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> a >> b;
		int A = depth[a], B = depth[b];
		int diff;
		if (A > B)
		{
			diff = A - B;
			first(a, diff);
		}
		else
		{
			diff = B - A;
			first(b, diff);
		}

		if (a == b) { result.push_back(a); continue; }
		else
		{
			for (int j = MAX_D - 1; j >= 0; --j)
			{
				if (data[a][j] != 1 && data[a][j] != data[b][j])
				{
					a = data[a][j];
					b = data[b][j];
				}
			}

			a = data[a][0];

			result.push_back(a);
		}
	}

	for (auto p : result)
	{
		std::cout << p << "\n";
	}
}