#include <iostream>
#include <vector>
#include <algorithm>

const int MAX = 1e6 + 1;

std::vector<std::pair<int, int>> data;
int N;

int main()
{
	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		std::cin >> tmp;

		data.push_back(std::make_pair(tmp, i));
	}

	std::sort(data.begin(), data.end());

	int current = data[0].first;
	int a = 0;

	for (int i = 0; i < data.size(); i++)
	{
		if (data[i].first == current)
		{
			data[i].first = a;
		}
		else
		{
			current = data[i].first;
			data[i].first = ++a;
		}
	}

	std::sort(data.begin(), data.end(), [](std::pair<int, int>& left, std::pair<int, int>& right)
	{
		return left.second < right.second;
	});

	for (int i = 0;i < data.size(); i++)
	{
		std::cout << data[i].first << " ";
	}
}