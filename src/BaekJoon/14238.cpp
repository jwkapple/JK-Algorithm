#include <iostream>
#include <string>

void Init()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
}

enum Case { NONE = 0, a, b, c };
const int MAX = 50;

bool DP[4][4][MAX][MAX][MAX];
int A = 0, B = 0, C = 0, size;

bool func(int p, int pp)
{
    if (A + B + C == 0) return true;

    auto& ret = DP[p][pp][A][B][C];

    if (ret == true) return false;

    if (A) {
        A--;
        if (func(a, p))
        {
            std::cout << 'A'; return true;
        }
        A++;
    }
    if (B && p != b) {
        B--;
        if (func(b, p))
        {
            std::cout << 'B'; return true;
        }
        B++;
    }
    if (C && p != c && pp != c) {
        C--;
        if (func(c, p))
        {
            std::cout << 'C'; return true;
        }
        C++;
    }

    ret = true;
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

    if (!func(Case::NONE, Case::NONE))std::cout << -1;
}