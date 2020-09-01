#include <iostream>
#include <vector>

int N;
int min = 0, max = 0;
int OP = 0;
std::vector<int> OPs;

int main()
{
	std::cin >> N;

	for (int i = 0;i < N; i++)
	{
		int tmp;
		std::cin >> tmp;
		if (tmp > OP)
		{
			OPs.clear();
			OP = tmp;
			OPs.push_back(i);
		}
		else if (tmp == OP)
		{
			OPs.push_back(i);
		}
	}

	min = OPs.front();
	max = OPs.back();

	int B = min;
	int R = N - max - 1;

	if (B < R) std::cout << 'R';
	else if (B == R) std::cout << 'X';
	else std::cout << 'B';
}