#include <iostream>
#include <vector>
#include <queue>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 3000 + 1;

std::vector<int> data[MAX];
bool visited[MAX];
int result[MAX];
int N;

int DFS(int num, int prev)
{
	if (visited[num]) return num;

	visited[num] = true;

	for (auto p : data[num])
	{
		if (p == prev) continue;

		int cur = DFS(p, num);
		if (cur == -1) continue;
		else
		{
			if (num == cur) return -1;
			else return cur;
		}
	}

	visited[num] = false;
	return -1;
}

int BFS(int num)
{
	int ret = 0;
	std::queue<pii> Q;

	Q.push(pii(num, 0));

	while (!Q.empty())
	{
		int size = Q.size();

		for (int a = 0; a < size; ++a)
		{
			auto[cur, prev] = Q.front(); Q.pop();

			if (visited[cur]) return ret;

			for (auto p : data[cur])
			{
				if (p != prev) Q.push(pii(p, cur));
			}
		}

		ret++;
	}

	return ret;
}
int main()
{
	Init();

	std::cin >> N;

	int A, B;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> A >> B;

		data[A].push_back(B);
		data[B].push_back(A);
	}

	DFS(1, 0);

	for (int i = 1; i <= N; ++i)
	{
		if (visited[i]) { result[i] = 0; continue; }

		else result[i] = BFS(i);
	}

	for (int i = 1; i <= N; ++i)
	{
		std::cout << result[i] << " ";
	}
}