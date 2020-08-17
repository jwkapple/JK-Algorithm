#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

const int MAX = 26;
std::string data[MAX];
bool visited[MAX][MAX];
int N;
int tmp = 0;
std::vector<int> result;

void dfs(int x, int y)
{
	if (x <= 0 || y < 1) return;
	if (x > N || y > N) return;
	if (data[x][y - 1] - '1' == 0 && !visited[x][y])
	{
		tmp++;
		visited[x][y] = true;

		dfs(x - 1, y);
		dfs(x + 1, y);
		dfs(x, y + 1);
		dfs(x, y - 1);
	}
}

int main()
{
	std::cin >> N;
	for (int i = 1; i <= N; i++)
	{
		std::cin >> data[i];
	}

	for (int x = 1; x <= N; x++)
	{
		for (int y = 1; y <= N; y++)
		{
			if (data[x][y - 1] - '1' == 0 && !visited[x][y])
			{
				dfs(x, y);
				result.push_back(tmp);
				tmp = 0;
			}
		}
	}

	int size = result.size();
	std::sort(result.begin(), result.begin() + size);

	std::cout << size << "\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << result[i] << "\n";
	}
}