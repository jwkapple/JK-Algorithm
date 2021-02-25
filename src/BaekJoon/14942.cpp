#include <iostream>
#include <vector>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e5 + 1, MAX_D = 18;

std::vector<int> result;
std::vector<pii> adj[MAX];

pii E[MAX];
int depth[MAX], data[MAX][MAX_D];

int N;

void MakeTree(int num)
{
	for (auto next : adj[num])
	{
		if (data[next.first][0] == -1)
		{
			data[next.first][0] = num;
			depth[next.first] = depth[num] + next.second;
			MakeTree(next.first);
		}
	}
}
int main() {

	Init();

	std::cin >> N;

	int tmp;
	for (int i = 1; i <= N; ++i)
	{
		std::cin >> tmp;
		E[i] = pii(i, tmp);
		data[i][0] = -1;
	}

	int a, b, v;
	for (int i = 0; i < N - 1; ++i)
	{
		std::cin >> a >> b >> v;
		adj[b].push_back(pii(a, v));
		adj[a].push_back(pii(b, v));
	}

	data[1][0] = 0;
	MakeTree(1);

	for (int j = 1; j < MAX_D - 1; ++j)
	{
		for (int i = 1; i <= N; ++i)
		{
			data[i][j] = data[data[i][j - 1]][j - 1];
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		auto&[num, e] = E[i];
		for (int j = MAX_D - 1; j >= 0; --j)
		{
			int size = depth[num] - depth[data[num][j]];
			if (data[num][j] != 0 && e >= size)
			{
				e -= size;
				num = data[num][j];
			}
		}
		result.push_back(num);
	}

	for (auto p : result)
	{
		std::cout << p << "\n";
	}
}