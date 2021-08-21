#include <iostream>
#include <vector>

void Init()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1000 + 1;

std::vector<int> parent[MAX];
std::vector<int> result;
int construct[MAX], child[MAX];
int T, N, K, W, from, to, nValue;

int main()
{
    Init();

    std::cin >> T;

    while (T--)
    {
        std::cin >> N >> K;
        std::vector<int> value(N + 1);

        for (int i = 1; i <= N; ++i) { std::cin >> value[i]; }

        for (int i = 1; i <= K; ++i)
        {
            std::cin >> from >> to;
            parent[from].push_back(to);
            child[to]++;
        }

        std::cin >> W;

        while (child[W] != -1)
        {
            for (int i = 1; i <= N; ++i)
            {
                if (child[i] == -1) continue;

                if (child[i] == 0)
                {
                    child[i] = -1;
                    for (auto p : parent[i])
                    {
                        child[p]--;
                        nValue = construct[i] + value[i];
                        construct[p] = construct[p] > nValue ? construct[p] : nValue;
                    }
                }
            }
        }

        result.push_back(construct[W] + value[W]);
        for (int i = 1; i <= N; ++i)
        {
            child[i] = 0, construct[i] = 0;
            parent[i].clear();
        }
    }

    for (auto p : result)
    {
        std::cout << p << "\n";
    }
}