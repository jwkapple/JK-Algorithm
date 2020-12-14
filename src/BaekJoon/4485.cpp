#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

#define pii std::pair<int, int>
#define pip std::pair<int, pii>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

int dir[4][2] = { {-1,0}, {1,0},{0,-1},{0,1} };
std::priority_queue<pip, std::vector<pip>, std::greater<pip>> pq;
const int MAX = 140;
int data[MAX][MAX];
int dij[MAX][MAX];

std::vector<int> result;
int N;

void func(const int& N)
{
	if (!N) return;


	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			std::cin >> data[y][x];
			dij[y][x] = INT_MAX;
		}
	}

	pq.push(pip(data[0][0], pii(0, 0)));

	while (!pq.empty())
	{
		pip cur = pq.top();
		int& num = dij[cur.second.first][cur.second.second];
		int value = cur.first;
		pq.pop();

		if (num <= value) continue;

		num = value;

		for (int i = 0; i < 4; ++i)
		{
			int Y = cur.second.first + dir[i][0];
			int X = cur.second.second + dir[i][1];

			if (Y < N && Y >= 0 && X < N && X >= 0) { pq.push(pip(value + data[Y][X], pii(Y, X))); }
		}
	}
	result.push_back(dij[N - 1][N - 1]);
}

int main()
{
	Init();

	do { std::cin >> N; func(N); } while (N);

	for (int i = 0; i < result.size(); ++i)
	{
		std::cout << "Problem " << i + 1 << ": " << result[i] << "\n";
	}
}