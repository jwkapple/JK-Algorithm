#include <iostream>

void Init()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 300 + 1;

int max[MAX][MAX];
int data[MAX][MAX];
int result[MAX][MAX];
int N, M;

void func(int n, int m)
{
    if (!m) return;

    func(n - 1, result[n][m]);
    std::cout << m - data[n][result[n][m]] << "\n";
}
int main()
{
    Init();

    std::cin >> N >> M;

    int tmp;
    for (int i = 1; i <= N; ++i)
    {
        std::cin >> tmp;
        for (int j = 0; j <= M; ++j)
        {
            std::cin >> data[j][i];
        }
    }

    for (int i = 1; i <= M; ++i)
    {
        for (int j = N; j >= 1; --j)
        {
            for (int k = 0; k <= j; ++k)
            {
                if (max[i][j] < max[i - 1][j - k] + data[i][k])
                {
                    max[i][j] = max[i - 1][j - k] + data[i][k];
                    result[i][j] = j - k;
                }
            }
        }
    }

    std::cout << max[M][N] << "\n";
    func(M, N);
}