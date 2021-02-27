#include <iostream>
#include <vector>
#include <cstring>

#define pii std::pair<int, int>

void Init()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e5 + 1;

std::vector<pii> data[MAX];
bool visited[MAX];
int V, Cost = 0, Node = 0;

void func(int cur, int cost)
{
    if (visited[cur]) return;
    visited[cur] = true;

    if (Cost < cost) { Cost = cost, Node = cur; }

    for (int i = 0; i < data[cur].size(); ++i) { func(data[cur][i].first, cost + data[cur][i].second); }
}

int main(void)
{
    Init();

    std::cin >> V;

    int node;
    for (int i = 0; i < V; i++)
    {
        std::cin >> node;

        int tmp, v;
        while (true)
        {
            std::cin >> tmp;
            if (tmp == -1) break;

            std::cin >> v;
            data[node].push_back(pii(tmp, v));
        };
    }

    std::memset(visited, false, sizeof(visited));

    func(1, 0);

    std::memset(visited, false, sizeof(visited));

    Cost = 0;
    func(Node, 0);

    std::cout << Cost << "\n";
}
