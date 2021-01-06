#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int num = 3;
int X[num], Y[num];

int func(int a, int b, int c)
{
	int AA[2] = { Y[b] - Y[a], X[b] - X[a] };
	int BB[2] = { Y[c] - Y[a], X[c] - X[a] };
	int result = (AA[0] * BB[1] - AA[1] * BB[0]);;
	if (result < 0) return 1;
	else if (!result) return 0;
	else return -1;
}
int main()
{
	Init();

	for (int i = 0; i < 3; ++i) { std::cin >> X[i] >> Y[i]; }

	std::cout << func(0, 1, 2);
}