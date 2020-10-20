#include <iostream>
#include <algorithm>
#include <stack>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e5 + 1;

std::stack<int> data;
int square[MAX];
int N;
int result = 0;

int main()
{
	Init();

	std::cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		std::cin >> square[i];
	}

	data.push(0);
	for (int i = 1; i <= N + 1; ++i)
	{
		while (square[data.top()] > square[i] && !data.empty())
		{
			int height = square[data.top()];
			data.pop();
			int width = i - data.top() - 1;

			result = std::max(result, height * width);
		}

		data.push(i);
	}

	std::cout << result;
}