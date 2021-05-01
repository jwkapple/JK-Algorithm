#include <iostream>

void Init()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e5 + 1;

int parent[MAX], data[MAX], DP[MAX];
int N, M;

int func(int num)
{

    auto& ret = DP[num];

    if (num == 1) return ret = 0;
    if (ret != -1) return ret;

    return ret = data[num] + func(parent[num]);
}

int main()
{
    Init();

    std::cin >> N >> M;

    for (int i = 1; i <= N; ++i) { DP[i] = -1; }
    for (int i = 1; i <= N; ++i)
    {
        std::cin >> parent[i];
    }

    int A, B;
    for (int i = 0; i < M; ++i)
    {
        std::cin >> A >> B;

        data[A] += B;
    }
    for (int i = 1; i <= N; ++i)
    {
        std::cout << func(i) << " ";
    }
}