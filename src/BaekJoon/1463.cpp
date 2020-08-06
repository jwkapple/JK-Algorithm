#include <iostream>
#include <algorithm>

const int MAX = 1000001;

int mp[MAX];


int func(int num)
{
	if (num == 1) return 0;
	else
	{
		if (mp[num] == -1)
		{
			int result = func(num - 1) + 1;
			if (num % 3 == 0) result = std::min(result, func(num / 3) + 1);
			if (num % 2 == 0) result = std::min(result, func(num / 2) + 1);

			mp[num] = result;
		}
		return mp[num];
	}
}
int main()
{
	int N;
	std::cin >> N;

	std::fill(mp, mp + MAX, -1);

	std::cout << func(N);
}

