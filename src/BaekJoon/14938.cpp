#include <iostream>

void Init()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
}

const int MAX = 100 + 1;

int data[MAX], path[MAX][MAX];
int N, M, R, result = 0;

int main()
{
    Init();

    std::cin >> N >> M >> R;

    for (int i = 1; i <= N; ++i)
    {
        std::cin >> data[i];
    }

    int from, to, v;
    for (int i = 0; i < R; ++i)
    {
        std::cin >> from >> to >> v;
        path[from][to] = path[to][from] = v;
    }

    int value;
    for (int a = 1; a <= N; ++a)
    {
        for (int y = 1; y <= N; ++y)
        {
            if (y == a || !path[y][a])
                continue;

            for (int x = 1; x <= N; ++x)
            {
                if (y == x || x == a || !path[x][a])
                    continue;

                value = path[y][a] + path[a][x];
                if (path[y][x])
                {
                    path[y][x] = value > path[y][x] ? path[y][x] : value;
                    path[x][y] = path[y][x];
                }
                else
                    path[y][x] = path[x][y] = value;
            }
        }
    }

    for (int y = 1; y <= N; ++y)
    {
        int total = data[y];
        for (int x = 1; x <= N; ++x)
        {
            if (!path[y][x])
                continue;

            if (path[y][x] <= M)
                total += data[x];
        }

        result = result > total ? result : total;
    }

    std::cout << result;
}