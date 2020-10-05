#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

#ifdef TEST
#include <fstream>
std::ifstream readFile;
#endif // TEST

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

std::vector<int> negative;
std::vector<int> positive;
int resultL, resultR;
int N;

int main()
{
	Init();

	std::cin >> N;

	int tmp;
	for (int i = 0;i < N; i++)
	{
		std::cin >> tmp;
		if (tmp < 0) negative.push_back(tmp);
		else positive.push_back(tmp);
	}

	std::sort(negative.begin(), negative.end(), [](const int& left, const int& right) { return left > right; });
	std::sort(positive.begin(), positive.end());

	if (!negative.size())
	{
		std::cout << positive[0] << " " << positive[1];
		return 0;
	}
	if (!positive.size())
	{
		std::cout << negative[1] << " " << negative[0];
		return 0;
	}

	auto minus = negative.begin(); auto plus = positive.begin();

	long long min = 5e30;

	if (positive.size() >= 2)
	{
		long long pos = std::abs(positive[1] + positive[0]);
		if (pos < min)
		{
			min = pos;
			resultL = positive[0];
			resultR = positive[1];
		}
	}

	if (negative.size() >= 2)
	{
		long long neg = std::abs(negative[1] + negative[0]);
		if (neg < min)
		{
			min = neg;
			resultL = negative[1];
			resultR = negative[0];
		}
	}

	while (minus != negative.end() && plus != positive.end())
	{
		int comp = *minus + *plus;
		if (comp == 0)
		{
			resultL = *minus;
			resultR = *plus;
			break;
		}
		if (std::abs(comp) < min)
		{
			min = std::abs(comp);
			resultR = *plus;
			resultL = *minus;
		}

		if (comp < 0) plus++;
		else minus++;

		resultL, resultR;
	}

	std::cout << resultL << " " << resultR;
}