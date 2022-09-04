#include <iostream>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 1e5 + 1;
const int IMP = 1e8;
std::vector<int> result;
int data[MAX][4], DP[MAX][4];
int N, T;
int func(int y, int x);

int calc(int y, int x)
{
	return data[y][x] + func(y, x);
}

int func(int y, int x)
{
	if (y == N)
	{
		switch (x)
		{
		case 1:
		{
			return data[y][2];
		}

		case 2:
		{
			return 0;
		}

		case 3:
		{
			return IMP;
		}
		}
	}

	auto &ret = DP[y][x];

	if (ret)
		return ret;

	int min, L, M, R;
	switch (x)
	{
	case 1:
	{
		L = calc(y + 1, x);
		M = calc(y + 1, x + 1);
		R = calc(y, x + 1);
		break;
	}

	case 2:
	{
		L = calc(y + 1, x + 1);
		M = calc(y + 1, x - 1);
		R = calc(y + 1, x);
		break;
	}

	case 3:
	{
		L = calc(y + 1, x - 1);
		M = calc(y + 1, x);
		R = IMP;
		break;
	}
	}

	L = L > M ? M : L;
	L = L > R ? R : L;

	return ret = L;
}

int main()
{
	Init();

	std::cin >> N;

	while (N)
	{
		for (int y = 1; y <= N; ++y)
		{
			for (int x = 1; x <= 3; ++x)
			{
				std::cin >> data[y][x];
			}
		}

		result.push_back(func(2, 1));

		for (int y = 1; y <= N; ++y)
		{
			for (int x = 1; x <= 3; ++x)
			{
				DP[y][x] = 0;
			}
		}

		std::cin >> N;
	}

	for (int i = 0; i < result.size(); ++i)
	{
		std::cout << i + 1 << ". " << result[i] << "\n";
	}
}