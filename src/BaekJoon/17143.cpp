#include <iostream>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

struct Node
{
	int R;
	int C;
	int S;
	int D;
	int Z;

	Node(int r, int c, int s, int d, int z) : R(r), C(c), S(s), D(d), Z(z) {}
};

enum dir { NONE = 0, UP, DOWN, RIGHT, LEFT };

const int MAX = 100 + 1;

std::vector<Node> data;
int map[MAX][MAX];
int R, C, M, King = 0, result = 0;

void move(int i)
{
	auto&[r, c, s, d, z] = data[i];

	map[r][c] = 0;
	int speed;

	switch (d)
	{
	case UP:
		speed = s % (R * 2);
		if (speed < r) r -= speed;
		else { r = speed - r; d = DOWN; }
		break;
	case DOWN:
		speed = s % (R * 2);
		if (speed < R - r) r += speed;
		else { r = R * 2 - speed - r; d = UP; }
		break;
	case RIGHT:
		speed = s % (C * 2);
		if (speed < C - c) c += speed;
		else { c = C * 2 - speed - c; d = LEFT; }
		break;
	case LEFT:
		speed = s % (C * 2);
		if (speed < c) c -= speed;
		else { c = speed - c; d = RIGHT; }
		break;
	}

	if (data[map[r][c]].Z < z)
	{
		data[map[r][c]].Z = 0;

		map[r][c] = i;
	}
	else data[i].Z = 0;
}
int main()
{
	Init();

	std::cin >> R >> C >> M;

	int r, c, s, d, z;

	data.push_back(Node(0, 0, 0, 0, 0));
	for (int i = 1; i <= M; ++i)
	{
		std::cin >> r >> c >> s >> d >> z;

		data.push_back(Node(r, c, s, d, z));
		map[r][c] = i;
	}

	while (King <= C)
	{
		King++;

		int current = 1;
		while (current <= R)
		{
			auto& pos = map[current][King];
			if (pos)
			{
				auto& cur = data[pos];

				result += cur.Z;
				cur.Z = 0;
				pos = 0;

				break;
			}
			current++;
		}

		for (int i = 1; i <= M; ++i)
		{
			if (!data[i].Z) continue;


			move(i);
		}
	}

	std::cout << result;
}
