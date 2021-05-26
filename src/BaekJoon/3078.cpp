#include <iostream>
#include <vector>
#include <string>
#include <queue>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 3e5 + 1;

struct cmp
{
	bool operator()(int L, int R)
	{
		int l = std::abs(L);
		int r = std::abs(R);

		if (l == r) return L < R;
		else return l > r;
	}
};

std::priority_queue<int, std::vector<int>, cmp> Q[20 + 1];
int N, K;
long long result = 0;

int main()
{
	Init();

	std::cin >> N >> K;

	int size;
	std::string tmp;
	for (int i = 1; i <= N; ++i)
	{
		std::cin >> tmp;
		size = tmp.size();
		Q[size].push(i);
		Q[size].push((i + K)* -1);
	}

	for (int i = 2; i <= 20; ++i)
	{
		size = 0;
		auto& cur = Q[i];
		while (!cur.empty())
		{
			int v = cur.top(); cur.pop();

			if (v > 0)
			{
				result += size;
				size++;
			}
			else size--;
		}
	}

	std::cout << result;
}