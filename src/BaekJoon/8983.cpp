#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e5 + 1;

int shot[MAX];
int M, N, L, result = 0;

bool func(int from, int to, int y, int x)
{
	int mid = (from + to) / 2;
	int dist = shot[mid] - y;

	if (std::abs(dist) + x <= L) return true;

	if (from == to) return false;
	if (from + 1 == to)
	{
		mid += 1;
		dist = shot[mid] - y;

		if (std::abs(dist) + x <= L) return true;
		else return false;
	}

	if (dist < 0) return func(mid + 1, to, y, x);
	else return func(from, mid, y, x);
}

int main()
{
	Init();

	std::cin >> M >> N >> L;

	for (int i = 0;i < M; ++i) { std::cin >> shot[i]; }

	std::sort(shot, shot + M);

	int y, x;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> y >> x;

		if (x > L) continue;

		result += func(0, M - 1, y, x);
	}

	std::cout << result;
}