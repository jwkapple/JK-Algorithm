#include <iostream>
#include <vector>
#include <queue>

void Init()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
}

struct Node
{
    int Value;
    int From;
    int To;

    Node(){};
    Node(int v, int f, int t) : Value(v), From(f), To(t){};
};

bool operator>(const Node &L, const Node &R)
{
    return L.Value > R.Value;
}

const int MAX = 1000 + 1;

std::priority_queue<Node, std::vector<Node>, std::greater<Node>> Q;

int parent[MAX];
int N, M;

int find(int A)
{
    if (parent[A] <= 0)
        return A;
    return parent[A] = find(parent[A]);
}

void merge(int A, int B, int value)
{
    int pA = find(A);
    int pB = find(B);

    if (pA == pB)
        return;

    if (pA < pB)
    {
        parent[pA] += parent[pB] + value * -1;
        parent[pB] = pA;
    }
    else
    {
        parent[pB] += parent[pA] + value * -1;
        parent[pA] = pB;
    }
}
int main()
{
    Init();

    std::cin >> N >> M;

    int f, t, v;

    for (int i = 0; i < M; ++i)
    {
        std::cin >> f >> t >> v;

        Q.push(Node(v, f, t));
    }

    while (!Q.empty())
    {
        auto [value, A, B] = Q.top();
        Q.pop();

        int pA = find(A);
        int pB = find(B);

        if (pA == pB)
            continue;

        merge(pA, pB, value);
    }

    std::cout << parent[1] * -1;
}