#include <iostream>
#include <stack>

#define ll long long 
void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e5 + 2;

std::stack<int> stack;
int data[MAX];
ll result = 0;
int N;

int main()
{
	Init();

	std::cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		std::cin >> data[i];
	}

	stack.push(0);

	for (int i = 1; i <= N + 1; ++i)
	{
		while (!stack.empty() && data[stack.top()] > data[i])
		{
			ll height = data[stack.top()];
			stack.pop();

			ll width = i - stack.top() - 1;

			ll size = height * width;
			if (result < size) result = size;
		}

		stack.push(i);
	}

	std::cout << result;
}