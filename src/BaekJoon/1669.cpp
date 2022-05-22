#include <iostream>

#define ll long long
void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

ll X, Y;
int main()
{
	Init();

	std::cin >> X >> Y;

	if (X == Y)
	{
		std::cout << 0;
		return 0;
	}
	ll value = Y - X;
	ll i = 1;

	ll tmp;
	while (true)
	{
		tmp = i * i;
		if (value <= tmp)
		{
			if (value == tmp)
			{
				std::cout << i * 2 - 1;
				return 0;
			}
			break;
		}

		i++;
	}

	--i;
	value -= i * i;

	ll result = i * 2 - 1;

	for (ll k = i; k > 0; --k)
	{
		if (value == 0)
			break;

		if (value <= i)
		{
			std::cout << result + 1;
			return 0;
		}

		tmp = value / k;
		value -= tmp * k;
		result += tmp;
	}

	std::cout << result;
}