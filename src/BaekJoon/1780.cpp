#include <iostream>

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}
const int MAX = 2189;

int N;
int Minus = 0, Zero = 0, One = 0;

int data[MAX][MAX];

int func(int X, int Y, int size)
{
	if (size == 1)	return data[X][Y];

	int minus = 0, zero = 0, one = 0;
	int sz = size / 3;

	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			switch (func(X + x * sz, Y + y * sz, sz))
			{
			case -1: minus++; break;
			case 0: zero++; break;
			case 1: one++; break;
			}
		}
	}

	if (minus == 9) return -1;
	if (zero == 9) return 0;
	if (one == 9) return 1;

	Minus += minus;
	Zero += zero;
	One += one;

	return 2;
}
int main()
{
	Init();

	std::cin >> N;

	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < N; y++)
		{
			std::cin >> data[x][y];
		}
	}

	switch (func(0, 0, N))
	{
	case -1: Minus++; break;
	case 0: Zero++; break;
	case 1: One++; break;
	}

	std::cout << Minus << "\n";
	std::cout << Zero << "\n";
	std::cout << One << "\n";
}