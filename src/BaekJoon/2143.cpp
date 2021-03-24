#include <iostream>
#include <map>

#define ll long long

void Init()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1000 + 1;

std::map<ll, ll> data;
int A[MAX], B[MAX];
int T, N, M;
ll result = 0;

int main() {

    Init();

    std::cin >> T >> N;
    for (int i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }

    std::cin >> M;
    for (int i = 0; i < M; ++i)
    {
        std::cin >> B[i];
    }


    for (int i = 0; i < N; ++i)
    {
        ll total = 0;
        for (int j = i; j < N; ++j)
        {
            total += A[j];
            data[total]++;
        }
    }

    for (int i = 0; i < M; ++i)
    {
        ll total = 0;
        for (int j = i; j < M; ++j)
        {
            total += B[j];
            result += data[T - total];
        }
    }

    std::cout << result;
}