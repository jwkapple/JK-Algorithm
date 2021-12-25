#include <iostream>

void Init()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
}

int data[20][10];
int N;

int func(int prev, int num)
{
    if (num == 0)
    {
        return prev % 3 == 0 ? 1 : 0;
    }

    auto &ret = data[prev][num];

    if (ret)
        return ret;
    else
        return ret = func(prev, num - 1) + func(prev + 1, num - 1) + func(prev + 2, num - 1);
}

int main()
{
    Init();

    std::cin >> N;

    int result = func(1, N - 1) + func(2, N - 1);

    std::cout << result;
}