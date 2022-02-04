#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

enum Base
{
	OUT,
	HIT,
	DOUBLE,
	TRIPLE,
	HOMERUN
};
const int MAX = 50 + 1;

bool visited[10];
int roaster[10], data[MAX][10];
int N, current = 1, result = 0;

int calc(int inning)
{
	if (inning == N + 1)
		return 0;

	if (current == 10)
		current = 1;

	int out = 0, player, ret = 0;
	bool state[3];

	while (out != 3)
	{
		if (current == 10)
			current = 1;
		player = roaster[current];
		switch (data[inning][player])
		{
		case OUT:
		{
			out++;
			break;
		}
		case HIT:
		{
			if (state[2])
			{
				ret++;
				state[2] = false;
			}
			if (state[1])
			{
				state[2] = true;
				state[1] = false;
			}
			if (state[0])
			{
				state[1] = true;
			}

			state[0] = true;
			break;
		}
		case DOUBLE:
		{
			if (state[2])
			{
				ret++;
				state[2] = false;
			}
			if (state[1])
			{
				ret++;
				state[1] = false;
			}
			if (state[0])
			{
				state[2] = true;
				state[0] = false;
			}

			state[1] = true;
			break;
		}
		case TRIPLE:
		{
			if (state[2])
			{
				ret++;
				state[2] = false;
			}
			if (state[1])
			{
				ret++;
				state[1] = false;
			}
			if (state[0])
			{
				ret++;
				state[0] = false;
			}

			state[2] = true;
			break;
		}
		case HOMERUN:
		{
			for (int i = 0; i < 3; ++i)
			{
				if (state[i])
				{
					ret++;
					state[i] = false;
				}
			}

			ret++;
			break;
		}
		}
		current++;
	}

	return ret + calc(inning + 1);
}

void func(int cur)
{
	if (cur == 4)
	{
		func(cur + 1);
		return;
	}

	if (cur == 10)
	{
		current = 1;
		int value = calc(1);
		result = result > value ? result : value;

		return;
	}

	for (int i = 1; i <= 9; ++i)
	{
		if (!visited[i])
		{
			roaster[cur] = i;
			visited[i] = true;
			func(cur + 1);
			visited[i] = false;
		}
	}
}

int main()
{
	Init();

	std::cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= 9; ++j)
		{
			std::cin >> data[i][j];
		}
	}

	roaster[4] = 1;
	visited[1] = true;

	func(1);

	std::cout << result;
}