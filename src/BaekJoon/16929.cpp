#include <iostream>

void Init()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
}

enum Case { UP, DOWN, LEFT, RIGHT };
int dir[4][2]{ {1,0},{-1,0},{0,-1},{0,1} };
const int MAX = 50 + 1;

bool visited[MAX][MAX];
char map[MAX][MAX];

int N, M;

bool DFS(int y, int x, int prev)
{
    if (visited[y][x]) return true;

    visited[y][x] = true;

    for (int i = 0; i < 4; ++i)
    {
        if (i == prev) continue;

        int Y = y + dir[i][0];
        int X = x + dir[i][1];

        if (Y > 0 && Y <= N && X > 0 && X <= M)
        {
            if (map[Y][X] == map[y][x])
            {
                switch (i)
                {
                case RIGHT: if (DFS(Y, X, LEFT)) return true; break;
                case LEFT: if (DFS(Y, X, RIGHT)) return true; break;
                case UP: if (DFS(Y, X, DOWN)) return true; break;
                case DOWN: if (DFS(Y, X, UP)) return true; break;
                }
            }
        }
    }

    return false;
}

int main()
{

    Init();

    std::cin >> N >> M;

    for (int y = 1; y <= N; ++y)
    {
        for (int x = 1; x <= M; ++x)
        {
            std::cin >> map[y][x];
        }
    }

    for (int y = 1; y <= N; ++y)
    {
        for (int x = 1; x <= M; ++x)
        {
            if (visited[y][x]) continue;

            if (DFS(y, x, -1))
            {
                std::cout << "Yes";
                return 0;
            }
        }
    }

    std::cout << "No";
}