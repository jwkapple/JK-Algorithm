#include <iostream>
#include <vector>

const int MAX = 102;

bool data[MAX][MAX];
bool visited[MAX][MAX];
int result = -1;
int tmp = 0;

int N, M, K;

void dfs(int x, int y)
{
	if (data[x][y] && !visited[x][y])
	{
		tmp++;
		visited[x][y] = true;
		dfs(x + 1, y);
		dfs(x - 1, y);
		dfs(x, y + 1);
		dfs(x, y - 1);
	}
}
void func()
{
	for (int x = 1; x <= N; x++)
	{
		for (int y = 1; y <= M; y++)
		{
			if (data[x][y] && !visited[x][y])
			{
				dfs(x, y);
				result = result < tmp ? tmp : result;
				tmp = 0;
			}
		}
	}
}

int main()
{
	std::cin >> N >> M >> K;

	for (int a = 0; a < K; a++)
	{
		int x, y;

		std::cin >> x >> y;

		data[x][y] = true;
	}

	func();

	std::cout << result;
}