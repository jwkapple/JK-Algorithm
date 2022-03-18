#include <iostream>
#include <vector>

void Init()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
}

const int MAX = 250 + 1;

std::vector<int> result;
int data[MAX][MAX];
int N, M, K;

int main()
{
    Init();

    std::cin >> N >> M;

    for (int y = 1; y <= N; ++y)
    {
        for (int x = 1; x <= N; ++x)
        {
            if (y == x)
                continue;
            data[y][x] = -1;
        }
    }
    int u, v, b;
    for (int i = 0; i < M; ++i)
    {
        std::cin >> u >> v >> b;

        data[u][v] = 0;
        if (b)
            data[v][u] = 0;
    }

    std::cin >> K;

    for (int a = 1; a <= N; ++a)
    {
        for (int y = 1; y <= N; ++y)
        {
            if (y == a)
                continue;
            for (int x = 1; x <= N; ++x)
            {
                if (y == x || x == a)
                    continue;
            }
        }
    }
    int s, e;
    for (int i = 0; i < K; ++i)
    {
        std::cin >> s >> e;

        result.push_back(data[s][e]);
    }

    for (auto p : result)
    {
        std::cout << p << "\n";
    }
}