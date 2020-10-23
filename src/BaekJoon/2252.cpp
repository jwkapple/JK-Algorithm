#include <iostream>
#include <vector>
#include <queue>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e5 + 1;

std::queue<int> Q;
std::vector<int> data[MAX];
std::vector<int> result;
int stud[MAX];
bool visited[MAX];
int N, M;

int main()
{
	Init();

	std::cin >> N >> M;

	int front, back;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> front >> back;
		stud[back]++;
		data[front].push_back(back);
	}

	while (result.size() != N)
	{
		while (!Q.empty())
		{
			int cur = Q.front();
			Q.pop();

			for (int i = 0; i < data[cur].size(); i++) { stud[data[cur][i]]--; }
			result.push_back(cur);
		}

		for (int i = 1; i <= N; ++i)
		{
			if (!visited[i] && stud[i] == 0)
			{
				Q.push(i);
				visited[i] = true;
			}
		}
	}

	for (int i = 0; i < result.size(); ++i)
	{
		std::cout << result[i] << " ";
	}
}