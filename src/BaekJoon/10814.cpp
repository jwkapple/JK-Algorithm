#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
	int N;
	std::cin >> N;
	std::vector<std::pair<int, int>> container(N);
	std::vector<std::string> names(N);

	for (int i = 0; i < N; i++)
	{
		std::cin >> container[i].first;
		std::getline(std::cin, names[i]);
		container[i].second = i;
	}

	std::sort(container.begin(), container.end());

	for (int i = 0; i < N; i++)
	{
		std::cout << container[i].first << " " << names[container[i].second] << "\n";
	}
}