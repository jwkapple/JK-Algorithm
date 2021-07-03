#include <iostream>
#include <algorithm>
#include <queue>

#define ll long long

void Init()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
}

struct Node
{
    int Color;
    int Value;
    int Num;

    Node() {};
    Node(int c, int v, int n) : Color(c), Value(v), Num(n) {};
};

const int MAX = 2e5 + 2;

Node data[MAX];
std::queue<pii> Q;
ll result[MAX], DP[MAX];
int N;

int main()
{
    Init();

    std::cin >> N;

    int c, v;
    for (int i = 1; i <= N; ++i)
    {
        std::cin >> c >> v;

        data[i] = Node(c, v, i);
    }

    std::sort(data + 1, data + N + 1, [](Node L, Node R)
    { if (L.Value == R.Value) return L.Color < R.Color;
    return L.Value < R.Value;
    });

    ll tot = 0;
    int prev = -1;
    for (int i = 1; i <= N; ++i)
    {
        auto [color, value, num] = data[i];

        if (prev != value)
        {
            prev = value;
            result[num] = tot - DP[color];
        }

        DP[color] += value;
        tot += value;
    }

    for (int i = 1; i <= N; ++i)
    {
        std::cout << result[i] << "\n";
    }
}