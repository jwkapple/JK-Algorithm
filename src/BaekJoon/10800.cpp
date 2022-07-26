#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define pii std::pair<int, int>

void Init()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
}

const int MAX = 2e5 + 1;

std::priority_queue<pii, std::vector<pii>, std::greater<pii>> Q;

pii colorH[MAX];
int sum[MAX], info[MAX], history[2000 + 1], result[MAX];
int N;

int main()
{
    Init();

    std::cin >> N;

    int C, S;
    for (int i = 0; i < N; ++i)
    {
        std::cin >> C >> S;
        Q.push(pii(S, i));

        info[i] = C;
    }

    int color, total = 0;
    while (!Q.empty())
    {
        auto [size, ID] = Q.top();
        Q.pop();

        color = info[ID];

        auto [pSize, pID] = colorH[color];

        if (pSize == size)
            result[ID] = result[pID];
        else
            result[ID] = total - history[size] - sum[color];

        sum[color] += size;
        total += size;
        history[size] += size;
        colorH[color] = pii(size, ID);
    }

    for (int i = 0; i < N; ++i)
    {
        std::cout << result[i] << "\n";
    }
}