#include <iostream>

void Init()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e6 + 1;

int N, M, a = 0, b = 0;
int A[MAX], B[MAX];

int main()
{
    Init();

    std::cin >> N >> M;

    A[N] = 1e9 + 1;
    B[M] = 1e9 + 1;

    for (int i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }
    for (int i = 0; i < M; ++i)
    {
        std::cin >> B[i];
    }

    while (a != N || b != M)
    {
        if (A[a] < B[b] || b == M)
        {
            std::cout << A[a++] << " ";
        }
        else
        {
            std::cout << B[b++] << " ";
        }
    }
}