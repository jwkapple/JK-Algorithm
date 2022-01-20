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

const int MAX = 1e6 + 1;

std::priority_queue<pii, std::vector<pii>, std::greater<pii>> Q;
std::priority_queue<int, std::vector<int>, std::greater<int>> PQ;
int N, curS = 1;
int data[MAX];

int main()
{
	Init();

	std::cin >> N;
	int p, q;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> p >> q;
		Q.push(pii(p, q));
	}

	PQ.push(1);

	int tmp;
	while (!Q.empty())
	{
		auto [s, e] = Q.top();
		Q.pop();

		if (e >= 0)
		{
			if (PQ.empty())
			{
				Q.push(pii(e, -1 * (++curS)));
				data[curS]++;
			}
			else
			{
				tmp = PQ.top();
				PQ.pop();
				Q.push(pii(e, -1 * tmp));
				data[tmp]++;
			}
		}
		else
		{
			PQ.push(-1 * e);
		}
	}

	std::cout << curS << "\n";

	for (int i = 1; i <= curS; ++i)
	{
		std::cout << data[i] << " ";
	}
}