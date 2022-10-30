#include <iostream>
#include <queue>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 1e5 + 1;

std::queue<int> Q;
bool police[MAX], visited[MAX];
int N, S, D, F, B, K, result = -1;
int main()
{
	Init();

	std::cin >> N >> S >> D >> F >> B >> K;

	int tmp;
	for (int i = 0; i < K; ++i)
	{
		std::cin >> tmp;
		police[tmp] = true;
	}

	Q.push(S);

	int time = 0;
	while (!Q.empty() && result == -1)
	{
		int size = Q.size();

		for (int i = 0; i < size; ++i)
		{
			int cur = Q.front();
			Q.pop();
			if (visited[cur])
				continue;

			if (cur == D)
			{
				result = time;
				break;
			}

			visited[cur] = true;
			int forward = cur + F;
			if (forward <= N)
			{
				if (!police[forward] && !visited[forward])
					Q.push(forward);
			}

			int backward = cur - B;
			if (backward > 0)
			{
				if (!police[backward] && !visited[backward])
					Q.push(backward);
			}
		}
		time++;
	}

	if (result == -1)
		std::cout << "BUG FOUND";
	else
		std::cout << result;
} 