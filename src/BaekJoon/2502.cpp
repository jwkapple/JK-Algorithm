#include <iostream>

void Init()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
}

const int MAX = 30 + 1;

int data[MAX];

int D, K;

int main()
{
    Init();

    data[1] = 1;
    data[2] = 1;

    for (int i = 3; i <= 29; ++i)
    {
        data[i] = data[i - 1] + data[i - 2];
    }

    std::cin >> D >> K;

    int first = data[D - 2];
    int second = data[D - 1];

    int tmp = K / second;

    int total = K - tmp * second;
    for (int i = tmp; i > 0; --i)
    {
        if (total == 0)
        {
            total += second;
            continue;
        }

        if (total % first == 0)
        {
            std::cout << (total / first) << "\n"
                      << i;
            return 0;
        }

        total += second;
    }
}