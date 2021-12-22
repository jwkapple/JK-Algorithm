#include <iostream>
#include <vector>
#include <queue>

void Init()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
}

struct Node
{
    int Size;
    int Color;
    int Num;

    Node(){};
    Node(int s, int c, int n) : Size(s), Color(c), Num(n){};
};

bool operator<(Node L, Node R)
{
    if (L.Size == R.Size)
        return L.Color > R.Color;

    return L.Size > R.Size;
}

const int MAX = 2 * 1e5 + 1;

std::priority_queue<Node> PQ;
int Value[MAX], result[MAX];
int N, total = 0, curSize = 0, curValue = 0, curColor = 0, curColVal = 0;

int main()
{
    Init();

    std::cin >> N;

    int tColor, tSize;
    for (int i = 0; i < N; ++i)
    {
        std::cin >> tColor >> tSize;
        PQ.push(Node(tSize, tColor, i));
    }

    while (!PQ.empty())
    {
        auto [size, color, num] = PQ.top();
        PQ.pop();

        curColVal = curColor == color ? curColVal + size : 0;
        curValue = curSize == size ? curValue + size : 0;

        result[num] = total - Value[color] - curValue + curColVal;
        Value[color] += size;
        total += size;

        curSize = size;
    }

    for (int i = 0; i < N; ++i)
    {
        std::cout << result[i] << "\n";
    }
}