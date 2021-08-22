#include <iostream>
#include <algorithm>

void Init()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1001;

int data[MAX];
int N, cur = 0, total = 1, current;

int main()
{
    Init();

    std::cin >> N;

    for (int i = 0; i < N; ++i) { std::cin >> data[i]; }

    std::sort(data, data + N);

    while (true)
    {
        current = data[cur];
        if (current > total) break;

        total += current;
        cur++;
    }

    std::cout << total;
}