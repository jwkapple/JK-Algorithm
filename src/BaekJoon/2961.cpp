#include <iostream>
#include <stdlib.h>

#define pii std::pair<int, int>

void Init()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
}
const int MAX = 10 + 1;

pii data[MAX];
bool check[MAX];

int N, S, B, result = 1e9;

void func(int cur)
{
    int s = 1, b = 0;
    bool tmp = false;

    if (cur == N)
    {
        for (int i = 0; i < N; ++i)
        {
            if (check[i])
            {
                s *= data[i].first;
                b += data[i].second;
                tmp = true;
            }
        }

        if (tmp)
        {
            int tmp2 = std::abs(s - b);
            result = result > tmp2 ? tmp2 : result;
        }
        return;
    }

    check[cur] = true;
    func(cur + 1);
    check[cur] = false;
    func(cur + 1);
}
int main()
{
    Init();

    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {
        std::cin >> S >> B;
        data[i] = pii(S, B);
    }

    func(0);

    std::cout << result;
}