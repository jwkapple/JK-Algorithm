#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<int> data;

std::string N;
unsigned long result = 0;
bool is;
int main()
{
	std::ios_base::sync_with_stdio(false);

	std::cin >> N;

	for (int i = 0;i < N.size(); i++)
	{
		if (N[i] == '0') is = true;

		result += (N[i] - '0');
		data.push_back(N[i] - '0');
	}

	if (result % 3 != 0) is = false;

	std::sort(data.begin(), data.begin() + data.size(), [](int&left, int& right)
	{
		return left > right;
	});

	if (is)
	{
		for (int i = 0; i < data.size(); i++)
		{
			std::cout << data[i];
		}
	}

	else std::cout << -1;
}