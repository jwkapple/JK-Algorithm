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

std::queue<int> Q;
std::priority_queue<pii, std::vector<pii>, std::greater<pii>> PQ;

int N, S, T, result = 1;

int main()
{
	Init();

	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> S >> T;
		PQ.push(pii(S, T));
	}

	Q.push(1);
	while (!PQ.empty())
	{
		auto [time, value] = PQ.top();
		PQ.pop();

		if (value > 0)
		{
			if (Q.empty())
			{
				PQ.push(pii(value, ++result * -1));
			}
			else
			{
				PQ.push(pii(value, Q.front() * -1));
				Q.pop();
			}
		}
		else
		{
			Q.push(value * -1);
		}
	}

	std::cout << result;
}