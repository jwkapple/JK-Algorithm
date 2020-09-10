#include <iostream>
#include <map>
#include <queue>

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

std::queue<int> Q;
int result = -1;
std::map<int, int> visited;

int A, B;

void bfs()
{
	int cnt = 0;

	while (!Q.empty())
	{
		int size = Q.size();

		cnt++;

		for (int i = 0; i < size; i++)
		{
			unsigned long cur = Q.front();
			Q.pop();

			if (cur == B)
			{
				result = cnt;
				break;
			}

			if (visited.find(cur) == visited.end())
			{
				visited.insert(std::make_pair(cur, 1));

				if (cur > 1e9)
				{
					return;
				}

				unsigned long doubl = cur * 2;
				unsigned long multi = cur * 10 + 1;

				if (B >= doubl) Q.push(doubl);
				if (B >= multi) Q.push(multi);
			}
		}
	}
}
int main()
{
	Init();

	std::cin >> A >> B;

	Q.push(A);
	bfs();

	if (result == -1) std::cout << -1;
	else std::cout << result;
}