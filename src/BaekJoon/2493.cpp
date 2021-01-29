#include <iostream>
#include <stack>

#define pii std::pair<int, int>
void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 5e5 + 1;

std::stack<pii> S;
int result[MAX];
int N, current = 1;
int main()
{
	Init();

	std::cin >> N;

	S.push(pii(1e8 + 1, 0));
	int tmp;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> tmp;

		auto[size, num] = S.top();

		while (tmp > size)
		{
			S.pop();

			size = S.top().first;
			num = S.top().second;
		}

		S.push(pii(tmp, i + 1));
		result[current++] = num;
	}

	for (int i = 1; i < current; ++i)
	{
		std::cout << result[i] << " ";
	}
}