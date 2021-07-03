#include <iostream>
#include <algorithm>

#define pii std::pair<int, int>

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
const int MAX = 2e5 + 1;

pii DP[MAX]; // latest, value
Node data[MAX];
int result[MAX];
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

    std::sort(data, data + N + 1, [](Node L, Node R) { return L.Value < R.Value; });

    int cur, tot;
    for (int i = 1; i <= N; ++i)
    {
        auto [color, value, num] = data[i];
        tot = 0;

        if (DP[color].first)
        {
            cur = DP[i].first;
            tot += DP[i].second;
        }
        else cur = 0;

        for (int j = cur; j < i; ++j)
        {
            auto [nColor, nValue, nNum] = data[j];
            if (nColor == color) continue;

            tot += nValue;
        }

        DP[color] = pii(i, tot);
        result[num] = tot;
    }

    for (int i = 1; i <= N; ++i)
    {
        std::cout << result[i] << "\n";
    }
}