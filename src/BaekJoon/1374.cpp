#include <iostream>
#include <queue>
#include <vector>

#define pii std::pair<int, bool>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

enum Case
{
	OUT,
	IN
};
std::priority_queue<pii, std::vector<pii>, std::greater<pii>> Q;
int N;

int main()
{
	Init();

	std::cin >> N;

	int n, s, e;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> n >> s >> e;

		Q.push(pii(s, IN));
		Q.push(pii(e, OUT));
	}

	int total = 0, cur = 0, num = 0;

	while (!Q.empty())
	{
		auto [T, C] = Q.top();
		Q.pop();

		if (C == IN)
		{
			if (cur == 0)
				total++;
			else
				cur--;

			if (++num == n)
			{
				std::cout << total;
				return 0;
			}
		}
		else
			cur++;
	}
}