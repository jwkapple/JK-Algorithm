#include <iostream>
#include <vector>
#include <queue>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 2e5 + 1;

std::vector<int> data[MAX];
std::queue<int> Q;

int people[MAX], half[MAX];
int result[MAX];
int N, M, T = 0;

int main()
{
	Init();

	std::cin >> N;

	int tmp;
	for (int i = 1; i <= N; ++i)
	{
		std::cin >> tmp;
		while (tmp)
		{
			data[i].push_back(tmp);
			std::cin >> tmp;
		}

		tmp = data[i].size();
		tmp = tmp - tmp / 2;
		half[i] = tmp;

		result[i] = -1;
	}

	std::cin >> M;

	for (int i = 0; i < M; ++i)
	{
		std::cin >> tmp;

		Q.push(tmp);
	}

	int size;
	while (!Q.empty())
	{
		size = Q.size();

		for (int a = 0; a < size; ++a)
		{
			auto i = Q.front();
			Q.pop();

			if (result[i] != -1)
				continue;

			result[i] = T;

			for (auto p : data[i])
			{
				people[p]++;

				if (result[p] == -1 && people[p] >= half[p])
				{
					Q.push(p);
				}
			}
		}

		T++;
	}

	for (int i = 1; i <= N; ++i)
	{
		std::cout << result[i] << " ";
	}
}