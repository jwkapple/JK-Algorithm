#include <iostream>
#include <stack>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

std::stack<int> Gt[7];
int N, P, result = 0;

void func(int x, int y)
{
	auto& cur = Gt[x];

	while (!cur.empty() && cur.top() >= y)
	{
		if (cur.top() == y) return;

		cur.pop();
		result++;
	}

	cur.push(y);
	result++;
}

int main()
{
	Init();

	std::cin >> N >> P;

	int x, y;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> x >> y;

		func(x, y);
	}

	std::cout << result;
}