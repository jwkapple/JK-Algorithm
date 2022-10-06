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

const int MAX = 1e5 + 1;

int data[MAX];
int N, S, result = 1e9;

int main()
{
	Init();

	std::cin >> N >> S;

	for (int i = 1; i <= N; ++i)
	{
		std::cin >> data[i];
	}

	int L = 1, R = 1, total = data[1];
	while (L <= R)
	{
		if (total >= S)
		{
			int interval = R - L;
			result = result < interval ? result : interval;
			total -= data[L++];
		}
		else
		{
			if (R == N)
				break;

			total += data[++R];
		}
	}

	if (result == 1e9)
		std::cout << 0;
	else
		std::cout << result + 1;
}