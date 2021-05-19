#include <iostream>
#include <stdlib.h>
#include <climits>

#define ll long long
#define pii std::pair<int, int>

void Init()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
}

int Dir[4][2] = { {-1,0},{1, 0},{0,-1},{0, 1} };
const int MAX = 1e5 + 1;

pii data[MAX];
ll DP[MAX][4];
int N;
ll result = LLONG_MAX;

ll dist(int y, int x, int pY, int pX)
{
    return std::abs(y - pY) + std::abs(x - pX);
}

ll func(int num, int dir)
{
    if (num == N) return 0;

    auto& ret = DP[num][dir];
    if (ret) return ret;

    ll min = LLONG_MAX;
    auto [y, x] = data[num];
    y += Dir[dir][0], x += Dir[dir][1];

    auto [nY, nX] = data[num + 1];
    for (int i = 0; i < 4; ++i)
    {
        ll value = dist(y, x, nY + Dir[i][0], nX + Dir[i][1]) + func(num + 1, i);
        min = min < value ? min : value;
    }

    return ret = min;
}

int main()
{
    Init();

    std::cin >> N;

    int y, x;

    for (int i = 0; i <= N; ++i)
    {
        std::cin >> y >> x;
        data[i] = pii(y, x);
    }

    auto [Y, X] = data[0];
    auto [Py, Px] = data[1];
    for (int i = 0; i < 4; ++i)
    {
        ll cur = dist(Y, X, Py + Dir[i][0], Px + Dir[i][1]) + func(1, i);
        result = result > cur ? cur : result;
    }

    std::cout << result;
}