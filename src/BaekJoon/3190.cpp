#include <iostream>
#include <deque>
#include <queue>

#define pii std::pair<int, int>
#define pic std::pair<int, char>
#define mp std::make_pair

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 101;
int dir[4][2] = { {-1,0}, {1,0},{0,-1},{0,1} };
enum Dir { up, down, left, right };
int table[MAX][MAX];
std::deque<pii> body;
std::queue<pic> move;

int N, K, L, head;
int result = 0;

void Turn(char di)
{
	switch (head)
	{
	case up: if (di == 'L') head = left; else head = right; break;
	case down: if (di == 'L') head = right; else head = left; break;
	case left: if (di == 'L') head = down; else head = up; break;
	case right: if (di == 'L') head = up; else head = down; break;
	}

	move.pop();
}

void Game()
{
	while (++result)
	{
		int Y = body.front().first + dir[head][0];
		int X = body.front().second + dir[head][1];

		if (Y == 0 || X == 0 || Y == N + 1 || X == N + 1) break;

		if (table[Y][X] == 1) break;
		if (table[Y][X] != -1) { table[body.back().first][body.back().second] = 0; body.pop_back(); }
		body.push_front(mp(Y, X)); table[Y][X] = 1;

		if (result == move.front().first) Turn(move.front().second);
	}
}

int main()
{
	Init();

	std::cin >> N >> K;

	int x, y;
	for (int i = 0;i < K; ++i)
	{
		std::cin >> y >> x;
		table[y][x] = -1;
	}

	std::cin >> L;

	int sec; char di;
	for (int i = 0; i < L; ++i)
	{
		std::cin >> sec >> di;
		move.push(mp(sec, di));
	}

	move.push(mp(-1, -1));

	body.push_back(mp(1, 1));
	table[1][1] = 1;
	head = right;

	Game();

	std::cout << result;
}