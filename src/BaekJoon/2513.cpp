#include <iostream>
#include <queue>
#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

std::priority_queue<pii> left, right;

int N, S, K, result = 0;

void func(std::priority_queue<pii> Q)
{
	while (!Q.empty())
	{
		int remain = K;

		auto [distance, student] = Q.top();
		Q.pop();

		result += distance;

		if (remain < student)
		{
			Q.push(pii(distance, student - remain));
			remain = 0;
		}
		else
			remain -= student;

		while (remain > 0 && !Q.empty())
		{
			auto [nDistance, nStudent] = Q.top();
			Q.pop();

			if (nStudent > remain)
			{
				Q.push(pii(nDistance, nStudent - remain));
				remain = 0;
			}
			else
			{
				remain -= nStudent;
			}
		}
	}
}
int main()
{
	Init();

	std::cin >> N >> K >> S;

	int location, value;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> location >> value;

		if (location < S)
			left.push(pii(S - location, value));
		else
			right.push(pii(location - S, value));
	}

	func(left);
	func(right);

	std::cout << result * 2;
}