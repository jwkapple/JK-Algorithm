#include <iostream>

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

unsigned long A, B, C;

unsigned long func(unsigned long A, unsigned long B)
{
	if (B == 0) return 1;
	if (B == 1) return A;

	if (B % 2 != 0) return  func(A, (B - 1))* A;

	unsigned long result = func(A, B / 2);

	result %= C;

	return result * result % C;
}
int main()
{
	Init();

	std::cin >> A >> B >> C;

	std::cout << func(A, B) % C;
}