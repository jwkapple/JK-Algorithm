#include <iostream>
#include <vector>
#include <queue>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 2e4 + 1;

std::vector<int> path[MAX];
int length[MAX];
int N, M;

int main()
{
	Init();

	std::cin >> N >> M;

	int A, B;

	for (int i = 0; i < M; ++i)
	{
		std::cin >> A >> B;

		path[A].push_back(B);
		path[B].push_back(A);
	}

	std::queue<int> Q;
	Q.push(1);

	int value = 1, cur;
	while (!Q.empty())
	{
		bool isDone = false;
		int size = Q.size();

		for (int i = 0; i < size; ++i)
		{
			int cur = Q.front();
			Q.pop();

			if (length[cur])
				continue;

			isDone = true;
			length[cur] = value;

			for (auto p : path[cur])
			{
				if (!length[cur])
					Q.push(p);
			}
		}

		if (isDone)
			value++;
	}

	value--;

	int minimum = 0, total = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (length[i] == value)
		{
			if (minimum == 0)
				minimum = i;
			total++;
		}
	}

	std::cout << minimum << " " << value - 1 << " " << total;
}