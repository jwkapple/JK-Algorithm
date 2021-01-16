#include <iostream>

#define point std::pair<int, int>
#define ll long long

enum class Direction { HORIZONTAL, VERTICAL, DIAGONAL };

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

point operator +(point L, point R) { return point(L.first + R.first, L.second + R.second); }

const int MAX = 32 + 1;

struct Node
{
	point L;
	point R;
	Direction D;

	Node(point l, point r, Direction d) : L(l), R(r), D(d) {};
};

ll push(point L, point R, Direction D);
ll BFS(Node Current);
bool dp(point L, point R);

ll DP[MAX][MAX][MAX][MAX];
bool map[MAX][MAX];
ll N, result = 0;
point finish;

bool dp(point L, point R)
{
	auto [ly, lx] = L; auto [ry, rx] = R;

	return DP[ly][lx][ry][rx];
}

ll BFS(Node Current)
{
	auto [L, R, D] = Current; auto [y, x] = R;

	auto& cur = DP[L.first][L.second][y][x];
	if (dp(L, R)) return cur;

	if (R == finish) return cur = 1;

	switch (D)
	{
	case Direction::HORIZONTAL:
		if (map[y][x + 1]) cur += push(L, R, Direction::HORIZONTAL);
		if (map[y + 1][x + 1] && map[y][x + 1] && map[y + 1][x]) cur += push(L, R, Direction::DIAGONAL);
		break;
	case Direction::VERTICAL:
		if (map[y + 1][x]) cur += push(L, R, Direction::VERTICAL);
		if (map[y + 1][x + 1] && map[y][x + 1] && map[y + 1][x]) cur += push(L, R, Direction::DIAGONAL);
		break;
	case Direction::DIAGONAL:
		if (map[y][x + 1]) cur += push(L, R, Direction::HORIZONTAL);
		if (map[y + 1][x]) cur += push(L, R, Direction::VERTICAL);
		if (map[y + 1][x + 1] && map[y][x + 1] && map[y + 1][x]) cur += push(L, R, Direction::DIAGONAL);
		break;
	}

	return cur;
}

ll push(point L, point R, Direction D)
{
	int y = 0, x = 0;
	switch (D)
	{
	case Direction::HORIZONTAL: { x++; break; }
	case Direction::VERTICAL: { y++;  break; }
	case Direction::DIAGONAL: { y++; x++; break; }
	}

	point l = R; point r = R + point(y, x);

	return BFS(Node(l, r, D));
}

int main() {

	Init();

	std::cin >> N;

	finish = point(N, N);

	int tmp;
	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= N; ++x)
		{
			std::cin >> tmp;
			if (!tmp) map[y][x] = true;
		}
	}

	std::cout << BFS(Node(point(1, 1), point(1, 2), Direction::HORIZONTAL));
}