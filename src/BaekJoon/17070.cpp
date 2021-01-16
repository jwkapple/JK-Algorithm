#include <iostream>
#include <queue>

#define point std::pair<int, int>
enum class Direction { HORIZONTAL, VERTICAL, DIAGONAL };

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

point operator +(point L, point R) { return point(L.first + R.first, L.second + R.second); }

const int MAX = 16 + 1;

struct Node
{
	point L;
	point R;
	Direction D;

	Node(point l, point r, Direction d) : L(l), R(r), D(d) {};
};

std::queue<Node> Q;
bool map[MAX][MAX];
int N, result = 0;
point finish;

Direction find(point L, point R)
{
	int Y = L.first - R.first;
	int X = L.second - R.second;

	if (!Y && X) return Direction::HORIZONTAL;
	if (Y && !X) return Direction::VERTICAL;
	if (Y && X) return Direction::DIAGONAL;
}
void push(point L, point R, Direction D)
{
	int y = 0, x = 0;
	switch (D)
	{
	case Direction::HORIZONTAL: { x++; break; }
	case Direction::VERTICAL: { y++;  break; }
	case Direction::DIAGONAL: { y++; x++; break; }
	}

	point l = R; point r = R + point(y, x);

	Q.push(Node(l, r, D));
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

	Q.push(Node(point(1, 1), point(1, 2), Direction::HORIZONTAL));

	while (!Q.empty())
	{
		int size = Q.size();

		for (int i = 0; i < size; ++i)
		{
			auto [L, R, D] = Q.front(); Q.pop();
			auto [y, x] = R;

			if (R == finish) { result++; continue; }

			switch (D)
			{
			case Direction::HORIZONTAL:
				if (map[y][x + 1]) push(L, R, Direction::HORIZONTAL);
				if (map[y + 1][x + 1] && map[y][x + 1] && map[y + 1][x]) push(L, R, Direction::DIAGONAL);
				break;
			case Direction::VERTICAL:
				if (map[y + 1][x]) push(L, R, Direction::VERTICAL);
				if (map[y + 1][x + 1] && map[y][x + 1] && map[y + 1][x]) push(L, R, Direction::DIAGONAL);
				break;
			case Direction::DIAGONAL:
				if (map[y][x + 1]) push(L, R, Direction::HORIZONTAL);
				if (map[y + 1][x]) push(L, R, Direction::VERTICAL);
				if (map[y + 1][x + 1] && map[y][x + 1] && map[y + 1][x]) push(L, R, Direction::DIAGONAL);
				break;
			}
		}
	}

	std::cout << result;
}