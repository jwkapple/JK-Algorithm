#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

//4963
#ifdef TEST
#include <fstream>
std::ifstream readFile;
#endif // TEST

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

int pos[8][2] = { {1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {-1,1}, {1, -1},{-1, -1} };
const int MAX = 50;

std::vector<int> result;
std::queue<std::pair<int, int>> Q;
int data[MAX][MAX];
bool visited[MAX][MAX];
int W, H;

void bfs()
{
	while (!Q.empty())
	{
		for (int i = 0; i < Q.size(); i++)
		{
			std::pair<int, int> current = Q.front();
			Q.pop();

			int X, Y;
			for (int j = 0; j < 8; j++)
			{
				X = current.first + pos[j][0];
				Y = current.second + pos[j][1];

				if (X >= 0 && X < W && Y >= 0 && Y < H)
				{
					if (!visited[Y][X])
					{
						Q.push(std::make_pair(Y, X));
						visited[Y][X] = true;
					}
				}
			}
		}
	}
}
int main()
{
	Init();

#ifdef TEST
	readFile.open("testCase.txt");
	char w, h, c;

	readFile.get(w); readFile.get(); readFile.get(h);

	while (true)
	{
		if (w == 0 && h == 0) break;

		int num = 0;
		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				readFile.get(c); readFile.get();
				if (c == '1') data[y][x] = 1;
			}
		}

		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				if (!visited[y][x])
				{
					Q.push(std::make_pair(y, x));
					visited[y][x] = true;
					bfs();

					num++;
				}
			}
		}

		result.push_back(num);

#pragma region common
		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				data[y][x] = 0;
				visited[y][x] = false;
			}
		}

		readFile.get(w); readFile.get(); readFile.get(h);
#pragma endregion
	}
	readFile.close();
#endif // TEST

#ifndef TEST
	std::cin >> data;
#endif // !TEST

	for (int i = 0; i < result.size(); i++)
	{
		std::cout << result[i] << "\n";
	}
}