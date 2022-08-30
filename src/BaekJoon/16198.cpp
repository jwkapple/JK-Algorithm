#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

bool visited[10 + 1];

int N = 0, data[10 + 1];

int Add(int value)
{
	int L = value, R = value;
	while (true)
	{
		if (visited[L])
			L--;
		else
		{
			L = data[L];
			break;
		}
	}

	while (true)
	{
		if (visited[R])
			R++;
		else
		{
			R = data[R];
			break;
		}
	}

	return L * R;
}

int func()
{
	int max = 0;
	for (int i = 1; i < N - 1; ++i)
	{
		if (!visited[i])
		{
			visited[i] = true;
			int current = Add(i) + func();
			visited[i] = false;
			max = max > current ? max : current;
		}
	}

	return max;
}
int main()
{
	Init();

	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> data[i];
	}

	std::cout << func();
}
