#include <iostream>

void Init()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 110;

int data[MAX], DP[10010];
int N, K;

int main() {

    Init();
    std::cin >> N >> K;

    for (int i = 1; i <= N; ++i)
    {
        std::cin >> data[i];
    }

    DP[0] = 1;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = data[i]; j <= K; ++j)
        {
            DP[j] += DP[j - data[i]];
        }
    }

    std::cout << DP[K];
}