#include <iostream>

#define pii std::pair<int, int>

void Init()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
}

enum Case { DOWN = 0, LEFT, RIGHT };
int dir[3][2]{ {1,0},{0,-1},{0,1} };
const int MAX = 1000 + 1;

int map[MAX][MAX], path[MAX][MAX][3], DP[MAX][MAX];
int N, M;

int func(int y, int x, int d)
{
    auto& ret = path[y][x][d];

    if (y == N && x == M) return map[y][x];
    if (ret) return ret + map[y][x];

    ret = -2e9;
    for (int i = 0; i < 3; ++i)
    {
        switch (d)
        {
        case LEFT: if (i == RIGHT) continue; break;
        case RIGHT: if (i == LEFT) continue; break;
        }

        int Y = y + dir[i][0];
        int X = x + dir[i][1];

        if (Y > 0 && Y <= N && X > 0 && X <= M)
        {
            int current = func(Y, X, i);

            ret = ret > current ? ret : current;
        }
    }

    return ret + map[y][x];
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

    std::cout << func(1, 1, RIGHT);
}