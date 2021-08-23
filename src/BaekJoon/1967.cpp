#include <iostream>
#include <vector>

#define pii std::pair<int, int>

void Init()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e4 + 1;

std::vector<pii> data[MAX];

int N, result = 0, total, value;

int func(int num)
{
    if (!(data[num].size())) return 0;

    int first = 0, second = 0;
    for (auto p : data[num])
    {
        auto [to, v] = p;

        value = v + func(to);
        if (value > first) { second = first, first = value; continue; }
        if (value > second) { second = value; }
    }

    total = first + second;
    result = result > total ? result : total;

    return first;
}
int main()
{
    Init();

    std::cin >> N;

    int from, to, v;
    for (int i = 0; i < N - 1; ++i)
    {
        std::cin >> from >> to >> v;

        data[from].push_back(pii(to, v));
    }

    func(1);

    std::cout << result;
}