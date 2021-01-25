#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 50 + 1;

int data[10], result[MAX];
int N, P;

int main()
{
	Init();

	int s = 0;

	std::cin >> N;

	while (true)
	{
		int m = 50, idx, cnt = 0;
		for (int i = 0; i < N; ++i)
		{
			std::cin >> data[i];
			if (m >= data[i]) { m = data[i], idx = i; }
		}

		std::cin >> P;
		for (; P >= m;) { result[cnt++] = idx; P -= m; }

		for (int i = 0; i < cnt; i++)
		{
			for (int j = N - 1; j >= 0; j--)
			{
				if (data[j] <= P + m) { result[i] = j; P += m - data[j]; break; }
				if (!result[s]) s++, P += m;
			}
		}
	}

	for (int i = 0; i < s; ++i) std::cout << result[i];
}