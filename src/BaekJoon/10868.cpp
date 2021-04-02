#include <iostream>
#include <vector>

void Init()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
}
const int INF = 1e9;
const int MAX = 1 << 18;

std::vector<int> result;
int data[MAX * 2];
bool visited[MAX * 2];
int N, M;

void update(int num)
{
    visited[num] = true;
    while (num > 1)
    {
        num /= 2;
        int left = visited[num * 2] ? data[num * 2] : INF;
        int right = visited[num * 2 + 1] ? data[num * 2 + 1] : INF;

        data[num] = left > right ? right : left;
        visited[num] = true;
    }
}

int func(int L, int R, int from, int to, int num) // ÇöÀç/Expect
{
    if (R < from || L > to) return INF;
    if (num >= MAX)
    {
        if (visited[num]) return data[num];
        else return INF;
    }
    if (from <= L && R <= to) return data[num];

    int mid = (L + R) / 2;

    int left = func(L, mid, from, to, num * 2);
    int right = func(mid + 1, R, from, to, num * 2 + 1);

    return left > right ? right : left;
}
int main()
{
    Init();

    std::cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        std::cin >> data[MAX + i];
        update(MAX + i);
    }

    int from, to;
    for (int i = 0; i < M; ++i)
    {
        std::cin >> from >> to;

        result.push_back(func(1, MAX, from, to, 1));
    }

    for (auto p : result)
    {
        std::cout << p << "\n";
    }
}