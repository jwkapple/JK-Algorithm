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

std::queue<pii> Q;
std::priority_queue<pii, std::vector<pii>, std::greater<pii>> PQ;
long long N, result = 0;

int main()
{
	Init();

	std::cin >> N;

	int tmp;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> tmp;
		Q.push(pii(tmp, i));
	}

	Q.push(pii(1e9 + 1, N));

	while (!Q.empty())
	{
		auto [height, num] = Q.front();
		Q.pop();

		if (PQ.empty())
			PQ.push(pii(height, num));
		else
		{

			while (!PQ.empty())
			{
				auto [pHeight, pNum] = PQ.top();

				if (pHeight > height)
				{
					PQ.push(pii(height, num));
					break;
				}
				else
				{
					result += num - pNum - 1;
					PQ.pop();
				}
			}

			if (PQ.empty())
				PQ.push(pii(height, num));
		}
	}

	std::cout << result;
}