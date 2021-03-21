#include <iostream>
#include <vector>

#define pii std::pair<int, int>
void Init()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 500 + 1;
std::vector<bool> result;
int TC, N, M, W, S, E, T;
int main()
{
    Init();

    std::cin >> TC;

    while (TC--)
    {
        bool visited[MAX];
        int data[MAX];
        std::vector<pii> adj[MAX];
        bool ret = false;
        std::cin >> N >> M >> W;

        for (int i = 0; i < M; ++i)
        {
            std::cin >> S >> E >> T;

            adj[S - 1].push_back(pii(E - 1, T));
            adj[E - 1].push_back(pii(S - 1, T));
        }

        for (int i = 0; i < W; ++i)
        {
            std::cin >> S >> E >> T;
            T *= -1;
            adj[S - 1].push_back(pii(E - 1, T));
        }

        std::fill(data, data + N, 0);
        for (int a = 0; a < N; ++a)
        {
            for (int i = 0; i < N; ++i)
            {
                for (auto p : adj[i])
                {
                    auto [next, v] = p;
                    if (!visited[next])
                    {
                        data[next] = v + data[i];
                        visited[next] = true;
                    }

                    if (visited[next] && visited[i] && data[next] > data[i] + v)
                    {
                        if (a == N - 1) ret = true;
                        else data[next] = data[i] + v;
                    }
                }
            }
        }

        result.push_back(ret);
    }

    for (auto p : result)
    {
        if (p) std::cout << "YES\n";
        else std::cout << "NO\n";
    }
}