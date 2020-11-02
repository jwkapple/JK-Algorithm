#include <iostream>
#include <stack>
void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1001;

std::stack<int> S;
int num[MAX];
int D[MAX];
int P[MAX];

int N, cur = 0;

int main()
{
	Init();

	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> num[i];
	}

	for (int i = 0;i < N; ++i)
	{
		D[i] = 1;
		P[i] = -1;

		for (int j = 0; j < i; ++j)
		{
			if (num[j] < num[i] && D[i] < D[j] + 1)
			{
				P[i] = j;
				D[i] = D[j] + 1;
			}
		}
	}

	int max = 0, pos = 0;
	for (int i = 0;i < N; ++i)
	{
		if (max < D[i])
		{
			max = D[i];
			pos = i;
		}
	}

	while (true)
	{
		S.push(num[pos]);

		if (P[pos] == -1) break;

		pos = P[pos];


	}

	std::cout << S.size() << "\n";
	while (!S.empty())
	{
		std::cout << S.top() << " ";
		S.pop();
	}
}