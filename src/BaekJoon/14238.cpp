#include <iostream>
#include <string>

void Init()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
}

enum Case { NONE = 0, a, b, c };
const int MAX = 50 + 1;

int DP[MAX][4][4][MAX][MAX][MAX];
int A = 0, B = 0, C = 0, size;

bool func(int cur, int p, int pp, int A, int B, int C)
{
    if (cur == size) return true;

    auto& ret = DP[cur][p][pp][A][B][C];

    if (ret == -1) return false;

    if (A) {
        if (func(cur + 1, a, p, A - 1, B, C))
        {
            std::cout << 'A'; return true;
        }
    }
    if (B && p != b) {
        if (func(cur + 1, b, p, A, B - 1, C))
        {
            std::cout << 'B'; return true;
        }
    }
    if (C && p != c && pp != c) {
        if (func(cur + 1, c, p, A, B, C - 1))
        {
            std::cout << 'C'; return true;
        }
    }

    ret = -1;
    return false;
}
int main()
{
    Init();

    std::string tmp;
    std::cin >> tmp;

    size = tmp.size();
    for (int i = 0; i < size; ++i)
    {
        switch (tmp[i])
        {
        case 'A': A++; break;
        case 'B': B++; break;
        case 'C': C++; break;
        }
    }

    if (!func(0, Case::NONE, Case::NONE, A, B, C))std::cout << -1;
}