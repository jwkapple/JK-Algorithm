#include<iostream>
#include<algorithm>

#define f(i,l,r) for(int i=l;i<r;++i)

void Init()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e6 + 1;

int data[MAX];
int N;
bool func(int num) {

    std::cin >> N;
    for (int i = 0; i < N; ++i)
    {
        std::cin >> data[i];
    }

    std::sort(data, data + N);

    int left = 0, right = N - 1;
    while (left < right)
    {
        int total = data[left] + data[right];

        if (total == num)
        {
            std::cout << "yes " << data[left] << " " << data[right] << "\n";
            return true;
        }

        if (total > num) --right;
        else ++left;
    }
    return false;
}

int main() {

    Init();

    int tmp;
    while (std::cin >> tmp)
    {
        tmp *= 1e7;
        if (!func(tmp))
            std::cout << "danger" << "\n";
    }
}