#include <iostream>
#include <vector>
#include <queue>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

int dir[8][2]{{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
enum Case
{
	NOTHING = 0,
	ODD = 1,
	EVEN = 2
};
struct Node
{
	int Y;
	int X;
	int ID;

	Node(){};
	Node(int y, int x, int id) : Y(y), X(x), ID(id){};
};

bool operator<(const Node &L, const Node &R)
{
	if (L.Y == R.Y)
	{
		return L.X > R.X;
	}

	return L.Y > R.Y;
}

struct INFO
{
	int M;
	int S;
	int D;

	INFO(){};
	INFO(int m, int s, int d) : M(m), S(s), D(d){};
};

std::vector<INFO> ID;
std::queue<Node> Q;
std::priority_queue<Node> PQ;
int N, M, K, idNum = 0;

int main()
{
	Init();

	std::cin >> N >> M >> K;

	int r, c, m, s, d;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> r >> c >> m >> s >> d;
		ID.push_back(INFO(m, s, d));
		Q.push(Node(r, c, idNum++));
	}

	int tmp;
	int pY = 0, pX = 0, pDirection, tMass = 0, tSpeed = 0, total = 0, tDirection = 0;
	while (K--)
	{
		if (Q.empty())
			break;
		while (!Q.empty())
		{
			auto [y, x, id] = Q.front();
			Q.pop();
			auto [mass, speed, direction] = ID[id];

			int Y = y + dir[direction][0] * speed;
			int X = x + dir[direction][1] * speed;

			if (Y <= 0)
			{
				tmp = Y * -1;
				tmp = tmp / N;
				Y += (tmp + 1) * N;
			}
			else if (Y > N)
			{
				tmp = Y / N;
				Y -= tmp * N;
			}

			if (X <= 0)
			{
				tmp = X * -1;
				tmp = tmp / N;
				X += (tmp + 1) * N;
			}
			else if (X > N)
			{
				tmp = X / N;
				X -= tmp * N;
			}

			PQ.push(Node(Y, X, id));
		}

		auto [fy, fx, fid] = PQ.top();
		PQ.pop();
		auto [fMass, fSpeed, fDirection] = ID[fid];

		pY = fy, pX = fx, tMass = fMass, tSpeed = fSpeed, total = 1;

		tDirection = fDirection % 2 ? ODD : EVEN;
		pDirection = fDirection;

		while (!PQ.empty())
		{
			auto [y, x, id] = PQ.top();
			PQ.pop();
			auto [mass, speed, direction] = ID[id];

			// same as previous
			if (y == pY && x == pX)
			{
				tMass += mass;
				tSpeed += speed;
				total++;
				if (tDirection != NOTHING)
				{
					int curDirection = direction % 2 ? ODD : EVEN;
					tDirection = tDirection == curDirection ? tDirection : NOTHING;
				}
			}
			else
			{
				if (total > 1)
				{
					// Clean up
					int dMass = tMass / 5;
					if (dMass != 0)
					{
						int dSpeed = tSpeed / total;
						int base = tDirection == NOTHING;

						for (int i = 0; i < 4; ++i)
						{
							ID.push_back(INFO(dMass, dSpeed, base + i * 2));
							Q.push(Node(pY, pX, idNum++));
						}
					}
				}
				else
				{
					ID.push_back(INFO(tMass, tSpeed, pDirection));
					Q.push(Node(pY, pX, idNum++));
				}
				// Reset
				pY = y, pX = x, tMass = mass, tSpeed = speed, total = 1;
				pDirection = direction;
				tDirection = direction / 2 ? ODD : EVEN;
			}
		}

		if (total > 1)
		{
			int dMass = tMass / 5;
			if (dMass != 0)
			{
				int dSpeed = tSpeed / total;
				int base = tDirection == NOTHING;

				for (int i = 0; i < 4; ++i)
				{
					ID.push_back(INFO(dMass, dSpeed, base + i * 2));
					Q.push(Node(pY, pX, idNum++));
				}
			}
		}
		else
		{
			ID.push_back(INFO(tMass, tSpeed, pDirection));
			Q.push(Node(pY, pX, idNum++));
		}
	}

	int result = 0;
	while (!Q.empty())
	{
		result += ID[Q.front().ID].M;
		Q.pop();
	}

	std::cout << result;
}