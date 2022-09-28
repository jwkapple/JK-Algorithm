#include <iostream>
#include <vector>
#include <queue>

#define pii std::pair<int, int>
void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

std::priority_queue<pii, std::vector<pii>, std::greater<pii>> Q;
std::vector<pii> data;
int N, M, K;

int main()
{
	Init();

	std::cin >> N >> M >> K;

	int tV, tC;
	for (int i = 0; i < K; ++i)
	{
		std::cin >> tV >> tC;
		Q.push(pii(tC, tV));
	}

	int prev = -1, total = 0;
	while (!Q.empty())
	{
		auto [c, v] = Q.top();
		Q.pop();

		if (prev != c)
		{
			data.push_back(pii(prev, total));
			prev = c;
		}

		total += c;
	}

	data.push_back(pii(prev, total));

	int size = data.size();

	for (int i = 0; i < size; ++i)
	{
		auto [c, v] = data[i];

		if (v >= M)
		{
			std::cout << c;
			return 0;
		}
	}

	std::cout << -1;
}