#include <iostream>
#include <vector>
#include <queue>

#define pii std::pair<int, int>
void Init()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
}

std::priority_queue<pii, std::vector<pii>, std::greater<pii>> Q;
int right = 301;
int N, result = 0;
int main()
{

    Init();

    std::cin >> N;

    int lM, mD, rM, rD;
    for (int i = 0; i < N; ++i)
    {
        std::cin >> lM >> mD >> rM >> rD;
        Q.push(pii(lM * 100 + mD, rM * 100 + rD));
    }

    Q.push(pii(2000, 2000));
    int R = 0;
    while (!Q.empty())
    {
        auto [from, to] = Q.top();

        if (from >= right)
        {
            result++;
            right = R;

            if (right > 1130) break;

            continue;
        }

        Q.pop();
        R = R > to ? R : to;

    }

    if (!right) std::cout << 0;
    else  std::cout << result;
}