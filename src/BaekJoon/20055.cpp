#include <iostream>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 200 + 1;

std::vector<int> robot;
bool visit[MAX];
int str[MAX];
int N, K, total, result = 0;

int main()
{
	Init();

	std::cin >> N >> K;

	total = N * 2;

	for (int i = 1; i <= total; ++i)
	{
		std::cin >> str[i];
	}

	int from = 0, start = 1, down = N;
	while (true)
	{
		result++;
		start--;
		down--;

		if (start == 0)
			start = total;
		if (down == 0)
			down = total;

		for (int i = from; i < robot.size(); ++i)
		{
			if (robot[i] == down)
			{
				from++;
				visit[down] = false;
				continue;
			}

			int next = robot[i] + 1;
			if (next > total)
				next = 1;
			if (!visit[next] && str[next] > 0)
			{
				visit[robot[i]] = false;
				visit[next] = true;
				str[next]--;

				if (str[next] == 0)
					K--;

				if (next == down)
				{
					visit[next] = false;
					from++;
				}
			}
		}

		if (str[start] > 0)
		{
			robot.push_back(start);
			visit[start] = true;
			str[start]--;
			if (str[start] == 0)
				K--;
		}

		if (K <= 0)
		{
			break;
		}
	}

	std::cout << result;
}
