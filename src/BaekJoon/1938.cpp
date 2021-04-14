#include <iostream>
#include <string>
#include <queue>


#define pii std::pair<int, int>
void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

struct Node
{
	int Y;
	int X;
	bool L; // false :: Vertical, true :: Horizontal

	Node() {};
	Node(int y, int x, bool l) : Y(y), X(x), L(l) {};
};

enum Map { NONE = 0, WALL };
enum Case { UP, DOWN, LEFT, RIGHT, TURN };

int dir[4][2]{ {-1,0},{1, 0},{0,-1},{0,1} };

const int MAX = 50 + 1;

std::queue<Node> Q;
bool visited[MAX][MAX][2];
pii data[3], finish[3];
int map[MAX][MAX];
int N, result = 0;
Node Finish;

bool check(int y, int x, int l)
{
	auto[Y, X, L] = Finish;

	return (Y == y) && (X == x) && (L == l);
}

bool func(int y, int x, int l, int num)
{
	switch (num)
	{
	case UP:
	{
		if (l)
		{
			if (y - 1 > 0)
			{
				if (map[y - 1][x]) return false;
				else return true;
			}
			else return false;
		}
		else
		{
			if (y > 0)
			{
				if (map[y][x] || map[y][x - 1] || map[y][x + 1]) return false;
				else return true;
			}
			else return false;
		}

		break;
	}

	case DOWN:
	{
		if (l)
		{
			if (y + 1 <= N)
			{
				if (map[y + 1][x]) return false;
				else return true;
			}
			else return false;
		}
		else
		{
			if (y <= N)
			{
				if (map[y][x] || map[y][x - 1] || map[y][x + 1]) return false;
				else return true;
			}
			else return false;
		}

		break;
	}

	case LEFT:
	{
		if (l)
		{
			if (x > 0)
			{
				if (map[y][x] || map[y - 1][x] || map[y + 1][x]) return false;
				else return true;
			}
			else return false;
		}
		else
		{
			if (x - 1 > 0)
			{
				if (map[y][x - 1]) return false;
				else return true;
			}
			else return false;
		}
		break;
	}

	case RIGHT:
	{
		if (l)
		{
			if (x <= N)
			{
				if (map[y][x] || map[y - 1][x] || map[y + 1][x]) return false;
				else return true;
			}
			else return false;
		}
		else
		{
			if (x + 1 <= N)
			{
				if (map[y][x + 1]) return false;
				else return true;
			}
			else return false;
		}
		break;
	}
	}
}

bool turn(int Y, int X, bool l)
{
	for (int y = Y - 1; y <= Y + 1; ++y)
	{
		for (int x = X - 1; x <= X + 1; ++x)
		{
			if (y > 0 && y <= N && x > 0 && x <= N)
			{
				if (map[y][x]) return false;
			}
			else return false;
		}
	}

	return true;
}
int main()
{
	Init();

	std::cin >> N;

	std::string tmp;
	int cur = 0, curF = 0;
	for (int y = 1; y <= N; ++y)
	{
		std::cin >> tmp;
		for (int x = 1; x <= N; ++x)
		{
			switch (tmp[x - 1])
			{
			case'B': data[cur++] = pii(y, x); break;
			case'1': map[y][x] = Map::WALL; break;
			case'E': finish[curF++] = pii(y, x); break;
			}
		}
	}

	if (data[0].first - data[2].first == 0) Q.push(Node(data[1].first, data[1].second, false));
	else Q.push(Node(data[1].first, data[1].second, true));

	if (finish[0].first - finish[2].first == 0) Finish = Node(finish[1].first, finish[1].second, false);
	else Finish = Node(finish[1].first, finish[1].second, true);

	while (!Q.empty())
	{
		int size = Q.size();

		for (int a = 0; a < size; ++a)
		{
			auto[y, x, l] = Q.front(); Q.pop();

			if (visited[y][x][l]) continue;

			visited[y][x][l] = true;
			if (check(y, x, l))
			{
				std::cout << result;
				return 0;
			}

			for (int i = 0; i < 4; ++i)
			{
				int Y = y + dir[i][0];
				int X = x + dir[i][1];

				if (func(Y, X, l, i)) Q.push(Node(Y, X, l));
			}

			if (turn(y, x, l)) Q.push(Node(y, x, !l));
		}

		result++;
	}

	std::cout << 0;
}