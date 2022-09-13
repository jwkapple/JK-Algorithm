#include <iostream>
#define ll long long

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

ll y1, y2, y3, y4;
ll x1, x2, x3, x4;
ll pX, pY;
ll bottom;

int main()
{
	Init();

	std::cin >> x1 >> y1 >> x2 >> y2;
	std::cin >> x3 >> y3 >> x4 >> y4;

	bottom = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

	if (bottom == 0)
	{
		std::cout << 0;
		return 0;
	}

	pX = (x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4);
	pY = (x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4);

	ll Y1 = y1 * bottom;
	ll Y2 = y2 * bottom;

	if (pY > Y1 && pY < Y2)
	{
		std::cout << 1;
		return 0;
	}

	if (pY > Y2 && pY < Y1)
	{
		std::cout << 1;
		return 0;
	}

	std::cout << 0;
}