#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

int DP[60][60][60][60];
int data[3];
int N, result = 0;

int func(int A, int B, int C, int num)
{
	if (A <= 0 && B <= 0 && C <= 0) return num;

	A = A > 0 ? A : 0;
	B = B > 0 ? B : 0;
	C = C > 0 ? C : 0;

	auto& cur = DP[num][A][B][C];
	if (cur) return cur;

	int v = 1e9;
	int c;
	c = func(A - 9, B - 3, C - 1, num + 1);
	v = v > c ? c : v;
	c = func(A - 9, B - 1, C - 3, num + 1);
	v = v > c ? c : v;
	c = func(A - 3, B - 9, C - 1, num + 1);
	v = v > c ? c : v;
	c = func(A - 3, B - 1, C - 9, num + 1);
	v = v > c ? c : v;
	c = func(A - 1, B - 9, C - 3, num + 1);
	v = v > c ? c : v;
	c = func(A - 1, B - 3, C - 9, num + 1);
	v = v > c ? c : v;

	return cur = v + 1;
}

int main()
{
	Init();

	std::cin >> N;

	int tmp;
	for (int i = 0; i < N; ++i) { std::cin >> data[i]; }

	std::cout << func(data[0], data[1], data[2], 0) / 2;
}