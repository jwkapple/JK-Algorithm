#include <iostream>
#include <deque>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e5 + 1;
std::deque<int> Q;

int visited[MAX];
int N, K, result = 0;

int main()
{
	Init();

	std::cin >> N >> K;

	Q.push_front(N);

	int current = 1;
	while (!Q.empty() && !result)
	{
		int size = Q.size();

		for (int i = 0; i < size; ++i)
		{
			int cur = Q.front(); Q.pop_front();
			if (cur >= MAX) continue;
			if (cur == K)
			{
				visited[cur] = current;
				result = current;
				break;
			}
			if (visited[cur]) continue;

			visited[cur] = current;
			if (cur < K)
			{
				if (cur)
				{
					size++;
					Q.push_front(cur * 2);
					Q.push_back(cur - 1);
				}
				Q.push_back(cur + 1);
			}
			else
			{
				Q.push_back(cur - 1);
			}
		}

		current++;
	}

	std::cout << result - 1;
}