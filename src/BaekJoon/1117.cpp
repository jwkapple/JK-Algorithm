#include <iostream>

int main()
{
	unsigned long W, H, f, c, x1, y1, x2, y2;

	std::cin >> W >> H >> f >> c >> x1 >> y1 >> x2 >> y2;

	unsigned long entire = W * H;

	unsigned long fx1 = 0, fx2 = f;
	unsigned long lx1 = 0, lx2 = W - f;
	unsigned long n, m;

	if (fx2 < x1) n = 0;
	else
	{
		if (fx2 < x2) n = fx2 - x1;
		else n = x2 - x1;
	}

	if (lx2 < x1) m = 0;
	else
	{
		if (lx2 < x2) m = lx2 - x1;
		else m = x2 - x1;
	}

	unsigned long result = (n * (y2 - y1) + m * (y2 - y1)) * (c + 1);

	std::cout << entire - result;
}