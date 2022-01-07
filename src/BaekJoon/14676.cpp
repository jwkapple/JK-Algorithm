#include <iostream>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 1e5 + 1;

std::vector<int> path[MAX];

int built[MAX], able[MAX];
int N, M, K, X, Y;

bool build(int num)
{
	if (able[num])
		return false;
	if (!built[num])
	{
		for (auto p : path[num])
		{
			able[p]--;
		}
	}

	built[num]++;
	return true;
}

bool destroy(int num)
{

	if (!built[num])
		return false;
	if (!(--built[num]))
	{
		for (auto p : path[num])
		{
			able[p]++;
		}
	}

	return true;
}

int main()
{
	Init();

	std::cin >> N >> M >> K;

	for (int i = 0; i < M; ++i)
	{
		std::cin >> X >> Y;
		path[X].push_back(Y);
		able[Y]++;
	}

	for (int i = 0; i < K; ++i)
	{
		std::cin >> X >> Y;

		if (X == 1)
		{
			if (!build(Y))
			{
				std::cout << "Lier!";
				return 0;
			}
		}
		else
		{
			if (!destroy(Y))
			{
				std::cout << "Lier!";
				return 0;
			}
		}
	}

	std::cout << "King-God-Emperor";
}