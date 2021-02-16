#include <iostream>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e4 + 1;

std::vector<int> result;
int T, N;
bool visited[MAX];
int A, B, parent[MAX];

int main()
{
	Init();

	std::cin >> T;

	while (T--)
	{
		std::cin >> N;

		int from, to;
		for (int i = 0; i < N - 1; ++i)
		{
			std::cin >> from >> to;
			parent[to] = from;
		}

		std::cin >> A >> B;

		visited[A] = true, visited[B] = true;

		while (parent[A] || parent[B])
		{
			if (parent[A])
			{
				A = parent[A];
				if (visited[A])
				{
					result.push_back(A); break;
				}

				visited[A] = true;
			}

			if (parent[B])
			{
				B = parent[B];
				if (visited[B])
				{
					result.push_back(B); break;
				}

				visited[B] = true;
			}
		}

		for (int i = 0; i < N; ++i)
		{
			visited[i] = false;
			parent[i] = 0;
		}
	}

	for (int i = 0; i < result.size(); ++i)
	{
		std::cout << result[i] << "\n";
	}
}
