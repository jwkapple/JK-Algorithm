#include <iostream>
#include <vector>

const int MAX = 52;
int T, M, N, K;
bool data[MAX][MAX]{ true };
bool visited[MAX][MAX]{ false };
std::vector<int> result;
int tmpResult = 0;

void dfs(int x, int y)
{
	if (data[x][y] && !visited[x][y])
	{
		visited[x][y] = true;
		dfs(x + 1, y);
		dfs(x - 1, y);
		dfs(x, y + 1);
		dfs(x, y - 1);
	}

}
void func()
{
	for (int x = 1; x <= M; x++)
	{
		for (int y = 1; y <= N; y++)
		{
			if (data[x][y] && !visited[x][y])
			{
				dfs(x, y);
				tmpResult++;
			}
		}
	}

	result.push_back(tmpResult);
}
int main()
{
	std::cin >> T;

	for (int a = 0; a < T; a++)
	{
		std::cin >> M >> N >> K;

		for (int i = 0;i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
			{
				data[i][j] = false;
				visited[i][j] = false;
			}
		}

		int X, Y;
		for (int i = 0; i < K; i++)
		{
			std::cin >> X >> Y;
			data[X + 1][Y + 1] = true;
		}

		func();
		tmpResult = 0;
	}

	for (int i = 0; i < result.size(); i++)
	{
		std::cout << result[i] << "\n";
	}
}