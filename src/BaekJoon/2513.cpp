#include <iostream>
#include <queue>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

std::priority_queue<pii> PQ, MQ;

int N, K, S, result = 0;

int main()
{
	Init();

	std::cin >> N >> K >> S;

	int A, B;
	for (int i = 0;i < N; ++i)
	{
		std::cin >> A >> B;

		if (A > S) PQ.push(pii(A - S, B));
		else MQ.push(pii(S - A, B));
	}

	int cur = 0;
	while (!PQ.empty())
	{
		auto[pos, v] = PQ.top(); PQ.pop();

		if (cur == 0) result += pos * 2;
		if (cur + v < K) cur += v;
		else if (cur + v == K) cur = 0;
		else
		{
			PQ.push(pii(pos, v - K + cur));
			cur = 0;
		}
	}

	cur = 0;

	while (!MQ.empty())
	{
		auto[pos, v] = MQ.top(); MQ.pop();

		if (cur == 0) result += pos * 2;
		if (cur + v < K) cur += v;
		else if (cur + v == K) cur = 0;
		else
		{
			MQ.push(pii(pos, v - K + cur));
			cur = 0;
		}
	}

	std::cout << result;
}