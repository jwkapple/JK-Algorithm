#include <iostream>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

pii egg[8 + 1];
int isBroken[8 + 1];

int N, totalBroken = 0, result = 0;

void func(int cur)
{
	if (isBroken[cur] < 0)
	{
		func(cur + 1);
		return;
	}

	if (cur == N)
	{
		int total = 0;
		for (int i = 0; i < N; ++i)
		{
			if (isBroken[i] <= 0)
				total++;
		}

		result = result < total ? total : result;
		return;
	}

	int curWeight = egg[cur].second;
	bool isDone = false;
	for (int i = 0; i < N; ++i)
	{
		if (isBroken[i] <= 0 || i == cur)
			continue;

		isDone = true;
		isBroken[cur] -= egg[i].second;
		isBroken[i] -= curWeight;
		func(cur + 1);
		isBroken[cur] += egg[i].second;
		isBroken[i] += curWeight;
	}

	if (isDone == false)
		func(cur + 1);
}
int main()
{
	Init();

	std::cin >> N;

	int durability, weight;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> durability >> weight;
		egg[i] = pii(durability, weight);
		isBroken[i] = durability;
	}

	func(0);

	std::cout << result;
}