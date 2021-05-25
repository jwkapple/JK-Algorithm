#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 100 + 2;

int data[MAX][MAX];
int L, N, result = 0;

bool vertical(int num)
{
	int cur = data[num][1];
	int stack = 0, value;

	for (int x = 1; x <= N; ++x)
	{
		value = data[num][x];
		if (value == cur) stack++;
		else if (value == cur + 1) // upward
		{
			if (stack >= L)
			{
				cur = value;
				stack = 1;
			}
			else return false;
		}
		else if (value + 1 == cur) // downward
		{
			if (x + L - 1 > N) return false;

			for (int i = 0; i < L; ++i)
			{
				if (data[num][x + i] != value) return false;
			}

			x += L - 1;
			cur = value;
			stack = 0;
		}
		else return false;
	}
	return true;
}

bool horizontal(int num)
{
	int cur = data[1][num];
	int stack = 0, value;

	for (int y = 1; y <= N; ++y)
	{
		value = data[y][num];
		if (value == cur) stack++;
		else if (value == cur + 1) // upward
		{
			if (stack >= L)
			{
				cur = value;
				stack = 1;
			}
			else return false;
		}
		else if (value + 1 == cur) // downward
		{
			if (y + L - 1 > N) return false;

			for (int i = 0; i < L; ++i)
			{
				if (data[i + y][num] != value) return false;
			}

			y += L - 1;
			cur = value;
			stack = 0;
		}
		else return false;
	}

	return true;
}

int main()
{
	Init();

	std::cin >> N >> L;

	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= N; ++x)
		{
			std::cin >> data[y][x];
		}
	}

	for (int y = 1; y <= N; ++y)
	{
		if (vertical(y)) result++;
	}

	for (int x = 1; x <= N; ++x)
	{
		if (horizontal(x)) result++;
	}

	std::cout << result;
}