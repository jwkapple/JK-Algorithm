#include <iostream>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e5 + 1;

std::vector<int> result;

bool visited[MAX], tmp[MAX];
int data[MAX];
int T, N, total;

int func(int cur)
{
	if (tmp[cur]) return cur;
	if (visited[cur]) return -1;

	tmp[cur] = true;

	int side = func(data[cur]);
	if (side > 0)
	{
		visited[cur] = true;
		tmp[cur] = false;
		total--;

		if (side == cur) return -1;

		return side;
	}
	else
	{
		visited[cur] = true;
		tmp[cur] = false;
		return -1;
	}
}
int main()
{
	Init();

	std::cin >> T;

	while (T--)
	{

		std::cin >> N;

		total = N;

		for (int i = 1; i <= N; ++i)
		{
			std::cin >> data[i];
			if (data[i] == i)
			{
				visited[i] = true; total--;
			}
			else visited[i] = false;
		}

		for (int i = 1; i <= N; ++i)
		{
			if (visited[i]) continue;
			func(i);
		}

		result.push_back(total);
	}

	for (auto p : result)
	{
		std::cout << p << "\n";
	}
}