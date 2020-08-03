#include <iostream>

struct RGB
{
	unsigned long R;
	unsigned long G;
	unsigned long B;
};

void func(unsigned long R, unsigned long G, unsigned long B, RGB& result)
{
	unsigned long r, g, b;
	RGB tmp;

	r = result.G <= result.B ? result.G : result.B;
	tmp.R = r + R;

	g = result.R <= result.B ? result.R : result.B;
	tmp.G = g + G;

	b = result.R <= result.G ? result.R : result.G;
	tmp.B = b + B;

	result = tmp;
}
int main()
{
	unsigned long N;
	std::cin >> N;

	RGB result;
	result.R = result.G = result.B = 0;

	for (unsigned long i = 0; i < N; i++)
	{
		unsigned long R, G, B;
		std::cin >> R >> G >> B;

		func(R, G, B, result);
	}

	unsigned long min = result.R <= result.G ? result.R : result.G;

	min = min <= result.B ? min : result.B;

	std::cout << min;
}