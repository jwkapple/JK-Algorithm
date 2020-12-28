#include <iostream>
#include <string>
#include <algorithm>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1000 + 2;

std::string left, right;

int data[MAX][MAX];

void init()
{
	for (int i = 0; i <= left.size(); ++i) { data[i][0] = i; }
	for (int i = 0; i <= right.size(); ++i) { data[0][i] = i; }
}

int main()
{
	Init();

	std::cin >> left >> right;

	init();

	int l = left.size();
	int r = right.size();

	for (int y = 0; y < l; ++y)
	{
		for (int x = 0; x < r; ++x)
		{
			if (left[y] == right[x]) data[y + 1][x + 1] = data[y][x];
			else
			{
				data[y + 1][x + 1] = std::min(data[y][x] + 1, data[y][x + 1] + 1);
				data[y + 1][x + 1] = std::min(data[y + 1][x + 1], data[y + 1][x] + 1);
			}
		}
	}

	std::cout << data[l][r];
}