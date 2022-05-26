#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>

const int TARGET = 123456789;

typedef struct
{
	int y, x;
}Dir;

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int main()
{
	Init();
	int start = 0;

	for (int i = 0; i < 3; i++)

		for (int j = 0; j < 3; j++)
		{
			int num;
			std::cin >> num;

			if (num == 0) num = 9;
			start = start * 10 + num;
		}

	std::queue<int> q;
	std::map<int, int> visited;

	q.push(start);
	visited[start] = 0;

	while (!q.empty())
	{
		int cur = q.front();
		std::string s = std::to_string(cur);
		q.pop();

		if (cur == TARGET) break;

		int z = s.find('9');

		int y = z / 3;
		int x = z % 3;

		for (int i = 0; i < 4; i++)
		{
			int nextY = y + moveDir[i].y;
			int nextX = x + moveDir[i].x;

			if (0 <= nextY && nextY < 3 && 0 <= nextX && nextX < 3)
			{
				std::string temp = s;
				std::swap(temp[y * 3 + x], temp[nextY * 3 + nextX]);
				int next = std::stoi(temp);

				if (!visited.count(next))
				{
					visited[next] = visited[cur] + 1;
					q.push(next);
				}
			}
		}
	}
	if (!visited.count(TARGET))
		std::cout << -1 << "\n";
	else
		std::cout << visited[TARGET] << "\n";
	return 0;
}