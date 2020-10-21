#include <iostream>
#include <vector>
#include <stack>

#define ll long long

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e5 + 1;
std::vector<ll> result;
std::vector<int> data;

void func(const int& N)
{
	std::stack<int> square;
	ll value = 0;
	data.resize(N + 2);

	for (int i = 1; i <= N; ++i)
	{
		std::cin >> data[i];
	}

	square.push(0);

	for (int i = 1; i <= N + 1; i++)
	{
		while (!square.empty() && data[square.top()] > data[i])
		{
			ll height = data[square.top()];
			square.pop();
			ll width = i - square.top() - 1;

			ll size = height * width;
			if (size > value) value = size;
		}

		square.push(i);
	}

	result.push_back(value);
	data.clear();
}
int main()
{
	Init();

	int test;
	std::cin >> test;

	while (test)
	{
		func(test);

		std::cin >> test;
	}

	for (int i = 0;i < result.size(); ++i)
	{
		std::cout << result[i] << "\n";
	}
}