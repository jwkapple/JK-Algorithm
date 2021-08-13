#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long

void Init()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1000 + 1;

struct Node
{
    int From;
    int To;
    int Value;

    Node() {};
    Node(int f, int t, int v) : From(f), To(t), Value(v) {};
};

bool operator<(Node L, Node R) { return L.Value < R.Value; }

std::vector<Node> Q;

int parent[MAX];
int N;
ll result = 0;

int find(int num)
{
    auto& p = parent[num];
    if (num == p) return num;

    return p = find(p);
}

bool merge(int A, int B)
{
    int pA = find(A);
    int pB = find(B);

    if (pA == pB) return false;

    if (pA < pB) parent[pB] = pA;
    else parent[pA] = pB;

    return true;
}

int main()
{
    Init();

    std::cin >> N;

    int tmp;
    for (int y = 1; y <= N; ++y)
    {
        parent[y] = y;
        for (int x = 1; x <= N; ++x)
        {
            std::cin >> tmp;

            if (x <= y) continue;

            Q.push_back(Node(y, x, tmp));
        }
    }

    std::sort(Q.begin(), Q.end());
    for (auto p : Q)
    {
        auto [y, x, v] = p;
        if (merge(y, x)) result += v;
    }

    std::cout << result;
}