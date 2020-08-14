#include <iostream>
#include <vector>
#include <algorithm>

const int MAX = 100001;
std::vector<std::pair<int, int>> data(MAX);
int N;
int result = 0;
int current = 0;

void func()
{
	for (int i = 0;i < N; i++)
	{
		if (data[i].second >= current)
		{
			result++;
			current = data[i].first;
		}
	}
}

int main()
{
	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		int start, end;

		std::cin >> start >> end;

		data[i].first = end;
		data[i].second = start;
	}

	std::sort(data.begin(), data.begin() + N);

	func();

	std::cout << result;
}