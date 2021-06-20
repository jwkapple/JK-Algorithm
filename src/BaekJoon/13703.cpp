#include <iostream>
#include <cstring>

#define ll long long

void Init()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1000 + 1;

ll data[MAX][MAX];
ll H, S;

ll func(ll k, ll n) {

    auto& ret = data[k][n];

    if (ret != -1) return ret;
    if (k == 0) return 0;
    if (!n) return 1;

    ret = func(k + 1, n - 1) + func(k - 1, n - 1);
    return ret;
}
int main() {

    Init();

    std::cin >> H >> S;

    memset(data, -1, sizeof(data));

    std::cout << func(H, S);
}