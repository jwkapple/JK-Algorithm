#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

void Init()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
}

struct Node
{
    int Start;
    int End;
    int Cost;

    bool operator < (const Node& other) { return Cost < other.Cost; }
};

const int MAX = 1e5 + 1;

std::vector<Node> data;
int Parent[MAX];
int N, M, result = 0, num = 0;

int Find(int x)
{
    if (x == Parent[x]) return x;

    return Parent[x] = Find(Parent[x]);
}

bool Merge(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if (x == y) return false;
    Parent[x] = y;
    return true;
}

int main()
{
    Init();

    std::cin >> N >> M;

    for (int i = 1; i <= N; ++i)
    {
        Parent[i] = i;
    }

    int from, to, v;
    for (int i = 0; i < M; ++i)
    {
        std::cin >> from >> to >> v;
        data.push_back({ from, to, v });
    }

    std::sort(data.begin(), data.end());

    for (int i = 0; i < M; ++i)
    {
        auto [start, end, v] = data[i];

        if (Merge(start, end))
        {
            result += v;
            num++;
        }

        if (num == N - 2) break;
    }

    std::cout << result;
}