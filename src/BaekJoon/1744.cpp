#include <iostream>
#include <queue>
#include <vector>

void Init()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
}

std::priority_queue<int, std::vector<int>, std::greater<int>> min;
std::priority_queue<int> pos;
int N, result, zero = 0, one = 0;

int main() {

    Init();

    std::cin >> N;

    int tmp;
    for (int i = 0; i < N; ++i)
    {
        std::cin >> tmp;
        if (tmp < 0) min.push(tmp);
        else if (!tmp) zero++;
        else if (tmp == 1) one++;
        else pos.push(tmp);
    }

    while (pos.size() > 1)
    {
        int A = pos.top(); pos.pop();
        int B = pos.top(); pos.pop();

        result += A * B;
    }

    while (min.size() > 1)
    {
        int A = min.top(); min.pop();
        int B = min.top(); min.pop();

        result += A * B;
    }

    while (!min.empty() && zero) { min.pop(); zero--; }

    while (!min.empty()) { result += min.top(); min.pop(); }
    while (!pos.empty()) { result += pos.top(); pos.pop(); }

    std::cout << result + one;
}
