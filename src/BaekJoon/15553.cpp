#include <iostream>
#include <queue>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

std::priority_queue<int> Q;
int N, K;

int main()
{
	Init();

	std::cin >> N >> K;

	int start, end;
	int tmp, max = 0, prev = 0;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> tmp;

		if (i == 0)
		{
			prev = tmp;
			start = tmp;
		}

		Q.push(tmp - prev);

		prev = tmp;
	}

	end = tmp;

	int total = end - start + 1;

	while (--K)
	{
		total -= (Q.top() - 1);
		Q.pop();
	}

	std::cout << total;
}