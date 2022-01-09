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

const int MAX = 1000 + 1;

std::vector<int> width;
std::vector<pii> path[MAX];
bool visited[MAX];
int dij[MAX];

int P, W, C, V;

bool solve(int num)
{
    std::fill(dij, dij + P, 1e9);
    dij[C] = -1;

    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> Q;

    Q.push(pii(0, C));

    int cur, value;
    while (!Q.empty())
    {
        do
        {
            value = Q.top().first;
            cur = Q.top().second;
            Q.pop();
        } while (value > dij[cur] && !Q.empty());

        if (cur == V)
            return true;

        dij[cur] = value;

        for (auto p : path[cur])
        {
            auto [nValue, next] = p;

            if (nValue < num)
                continue;

            nValue += value;

            if (dij[next] > nValue)
            {
                dij[next] = nValue;
                Q.push(pii(nValue, next));
            }
        }

        if (Q.empty())
            break;
    }

    return false;
}

int func(int left, int right)
{
    if (left > right)
        return -1;
    if (left == right)
        return solve(width[left]) ? left : -1;

    int mid = (left + right) / 2;

    bool tmp = solve(width[mid]);

    if (tmp)
    {
        int ret = func(mid + 1, right);
        if (ret == -1)
            return mid;
        else
            return ret;
    }
    else
        return func(left, mid - 1);
}

int main()
{
    Init();

    std::cin >> P >> W >> C >> V;

    int from, to, v, tmp = 0;
    for (int i = 0; i < W; ++i)
    {
        std::cin >> from >> to >> v;

        width.push_back(v);
        path[from].push_back(pii(v, to));
        path[to].push_back(pii(v, from));
    }

    std::sort(width.begin(), width.end());
    dij[C] = -1;

    std::cout << width[func(0, W - 1)];
}