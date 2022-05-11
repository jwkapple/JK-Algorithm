#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 100 + 1;

int data[MAX];
int N;

char func(int idx, int value)
{
	int prev = data[idx - 1];
	if (value > prev && value < prev + idx + 4)
	{
		if (value == prev + 1)
			return 'm';
		else
			return 'o';
	}

	if (value <= prev)
	{
		return func(idx - 1, value);
	}

	return func(idx - 1, value - (prev + idx + 3));
}
int main()
{
	Init();

	std::cin >> N;

	int cur = 0;
	data[cur] = 3;
	while (true)
	{
		if (data[cur] >= N)
			break;

		data[cur + 1] = data[cur] * 2 + cur + 4;
		cur++;
	}

	std::cout << func(cur, N);
}