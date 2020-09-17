#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

int n;
double p[4]; // E, W, S, N
double result = 1;

int dir[4][2] = { {1,0},{-1,0},{0,-1},{0,1} };
bool visited[50][50];

void func(int x, int y, int cnt, double percentage)
{
	if (cnt == n) return;

	for (int i = 0;i < 4; i++)
	{
		int X = x + dir[i][0];
		int Y = y + dir[i][1];

		if (p[i] == 0) continue;
		percentage *= p[i];

		if (visited[X][Y]) result -= percentage;
		else
		{
			visited[X][Y] = true;
			func(X, Y, cnt + 1, percentage);
			visited[X][Y] = false;
		}

		percentage /= p[i];
	}
}
int main()
{
	Init();

	std::cin >> n;

	for (int i = 0;i < 4; i++)
	{
		double tmp;
		std::cin >> tmp;

		tmp /= 100.00;
		p[i] = tmp;
	}

	visited[14][14] = true;
	func(14, 14, 0, 1); // starting from middle

	std::cout.precision(11);
	std::cout << std::fixed;
	std::cout << result;
}