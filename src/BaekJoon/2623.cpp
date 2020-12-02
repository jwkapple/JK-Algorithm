#include <iostream>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1000 + 1;

std::vector<int> data[MAX];
std::vector<int> result;
int score[MAX];
bool visited[MAX];
int N, M, done = 0;

int main()
{
	Init();

	std::cin >> N >> M;

	int num;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> num;

		std::vector<int> tmp;
		tmp.resize(num);

		for (int j = 0; j < num; ++j) { std::cin >> tmp[j]; }

		for (int j = 0; j < num; ++j)
		{
			for (int k = j + 1; k < num; ++k)
			{
				data[tmp[j]].push_back(tmp[k]);
				score[tmp[k]]++;
			}
		}
	}

	bool current = true;
	while (done != N && current)
	{
		current = false;
		for (int i = 1; i <= N; ++i)
		{
			if (!score[i] && !visited[i])
			{
				current = true;
				result.push_back(i);
				for (int j = 0; j < data[i].size(); ++j) { score[data[i][j]]--; }
				visited[i] = true;
				done++;
			}
		}
	}

	if (!current) std::cout << 0;
	else
	{
		for (int i = 0; i < result.size(); ++i) { std::cout << result[i] << "\n"; }
	}
}