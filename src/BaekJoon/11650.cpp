#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int N;
	std::cin >> N;

	std::vector<std::pair<int, int>> container(N, std::make_pair<int, int>(2, 0));

	for (int i = 0; i < N; i++)
	{
		std::cin >> container[i].first >> container[i].second;
	}

	std::sort(container.begin(), container.end());

	for (int i = 0; i < N; i++)
	{
		std::cout << container[i].first << " " << container[i].second << "\n";
	}
}
