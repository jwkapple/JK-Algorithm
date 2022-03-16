#include <iostream>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 1024 + 1;

std::vector<int> result;
int data[MAX][MAX];
int N, M;

int main()
{
	Init();

	std::cin >> N >> M;

	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= N; ++x)
		{
			std::cin >> data[y][x];
			data[y][x] += data[y - 1][x] + data[y][x - 1] - data[y - 1][x - 1];
		}
	}

	int x1, y1, x2, y2;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> x1 >> y1 >> x2 >> y2;
		result.push_back(data[y2][x2] - data[y2][x1 - 1] - data[y1 - 1][x2] + data[y1 - 1][x1 - 1]);
	}

	for (auto p : result)
	{
		std::cout << p << "\n";
	}
}