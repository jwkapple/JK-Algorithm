#include <iostream>
#include <vector>
#include <queue>

struct Point
{
	int Value;
	int Left;
	int Right;

	Point() {};
	Point(int l, int r, int v) : Left(l), Right(r), Value(v) {};

	Point& operator <(Point& p)
	{
		return p.Value < this->Value;
	}
};


void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 21;

std::priority_queue<Point, std::vector<Point>, std::greater<Point>> pq;
int data[MAX][MAX];
int map[MAX][MAX];
bool visited[MAX];
int N, result = 0;

void push(int a, int b, int v)
{
	data[a][b] = v; data[b][a] = v;
	visited[a] = true; visited[b] = true;
}

void path(int root, int point)
{
	for (int i = 1; i <= N; ++i)
	{
		if (i == root || i == point) continue;
		if (visited[i])
		{
			int value = data[i][point] + data[point][root];

			if (!data[i][root]) { push(i, root, value); continue; }
			if (value < data[i][root]) data[i][root] = value;
		}
	}
}

void func(Point cur)
{
	if (!visited[cur.Left])
	{
		result += cur.Value;
		push(cur.Left, cur.Right, cur.Value);

		if (visited[cur.Right])
		{
			path(cur.Left, cur.Right);
		}

		return;
	}
	else
	{
		if (!visited[cur.Right])
		{
			result += cur.Value;
			push(cur.Left, cur.Right, cur.Value);

			path(cur.Left, cur.Right);
		}

		else
		{
			if (cur.Value < data[cur.Right][cur.Left])
			{
				result += cur.Value;
				push(cur.Left, cur.Right, cur.Value);
			}
		}
	}
}

int main()
{
	Init();

	std::cin >> N;

	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= N; ++x)
		{
			std::cin >> map[y][x];
			if (y < x) pq.push(Point(y, x, map[y][x]));
		}
	}

	while (!pq.empty())
	{
		func(pq.top());
		pq.pop();
	}
}