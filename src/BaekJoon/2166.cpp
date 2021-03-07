#include <iostream>
#include <vector>

#define pll std::pair<long, long>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

std::vector<pll> data;
long result;
int N;

long func(int X, int Y, int Z)
{
	auto [x1, y1] = data[X];
	auto [x2, y2] = data[Y];
	auto [x3, y3] = data[Z];

	return x1 * y2 + x2 * y3 + x3 * y1 - (y1 * x2 + y2 * x3 + y3 * x1);
}
int main() {

	Init();

	std::cin >> N;

	long x, y;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> x >> y;
		data.push_back(pll(x, y));
	}


	for (int i = 0; i < N - 2; ++i)
	{
		long tmp = 0;
		tmp += func(0, i + 1, i + 2);

		result += tmp;
	}

	result = std::abs(result);
	if (result % 2) std::cout << result / 2 << ".5";
	else std::cout << result / 2 << ".0";
}