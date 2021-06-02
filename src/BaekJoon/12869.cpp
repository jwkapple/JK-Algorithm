#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 60 + 1;
int DP[MAX][MAX][MAX];
int data[3];
int N;

int func(int A, int B, int C)
{
	if (A <= 0 && B <= 0 && C <= 0) return 0;

	A = A > 0 ? A : 0;
	B = B > 0 ? B : 0;
	C = C > 0 ? C : 0;

	auto& cur = DP[A][B][C];
	if (cur) return cur;

	int v = 1e9;
	int c;

	c = func(A - 9, B - 1, C - 3);
	v = v > c ? c : v;

	if (N >= 2)
	{
		c = func(A - 9, B - 3, C - 1);
		v = v > c ? c : v;
		c = func(A - 3, B - 9, C - 1);
		v = v > c ? c : v;

		if (N == 3)
		{
			c = func(A - 3, B - 1, C - 9);
			v = v > c ? c : v;
			c = func(A - 1, B - 9, C - 3);
			v = v > c ? c : v;
			c = func(A - 1, B - 3, C - 9);
			v = v > c ? c : v;
		}
	}

	return cur = v + 1;
}

int main()
{
	Init();

	std::cin >> N;

	int tmp;
	for (int i = 0; i < N; ++i) { std::cin >> data[i]; }

	std::cout << func(data[0], data[1], data[2]);
}