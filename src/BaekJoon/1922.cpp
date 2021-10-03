#include <iostream>
#include <vector>
#include <algorithm>

void Init()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
}

struct Node
{
    int Value;
    int From;
    int To;

    Node() {};
    Node(int v, int f, int t) : Value(v), From(f), To(t) {};
};

bool operator<(Node L, Node R)
{
    return L.Value < R.Value;
}

const int MAX = 1000 + 1;

std::vector<Node> data;
int parent[MAX];
int N, M, result = 0;

int find(int x)
{
    if (x == parent[x]) return x;
    else return parent[x] = find(parent[x]);
}

void merge(int x, int y)
{
    y = find(y);
    x = find(x);

    if (y > x) parent[y] = x;
    else parent[x] = y;
}

bool findParent(int x, int y)
{
    y = find(y);
    x = find(x);

    return y == x;
}
int main()
{
    Init();

    std::cin >> N >> M;

    int from, to, value;
    for (int i = 0; i < M; ++i)
    {
        std::cin >> from >> to >> value;
        if (from == to) continue;

        data.push_back(Node(value, from, to));
    }

    std::sort(data.begin(), data.end());
    for (int i = 1; i <= N; ++i) { parent[i] = i; }

    for (auto p : data)
    {
        auto [v, f, t] = p;

        if (!findParent(f, t))
        {
            merge(f, t);
            result += v;
        }
    }

    std::cout << result;
}