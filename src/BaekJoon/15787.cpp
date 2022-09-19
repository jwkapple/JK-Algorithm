#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 1e5 + 1;
const int IMP = 1 << 21;
bool visited[IMP + 1];
int data[MAX];
int N, M, result = 0;

void func(int a, int b, int c)
{
	int &cur = data[b];
	int value = 1 << c;

	switch (a)
	{
	case 1:
	{
		cur |= value;

		break;
	}
	case 2:
	{
		cur &= ~value;

		break;
	}
	case 3:
	{
		cur = cur << 1;
		cur &= (IMP - 1);

		break;
	}
	case 4:
	{
		cur = cur >> 1;
		cur &= ~1;
		break;
	}

	default:
		break;
	}
}

int main()
{
	Init();

	std::cin >> N >> M;

	int a, b, c;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> a;

		if (a == 1 || a == 2)
		{
			std::cin >> b >> c;
		}
		else
			std::cin >> b;
		func(a, b, c);
	}

	for (int i = 1; i <= N; ++i)
	{
		if (!visited[data[i]])
		{
			visited[data[i]] = true;
			result++;
		}
	}

	std::cout << result;
}