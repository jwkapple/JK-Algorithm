#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

const int MAX = 1e3 + 1;

std::priority_queue<int, std::vector<int>, std::greater<int>> assigment;
std::vector<std::pair<int, int>> result;

int N, current = 0;
void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

int main()
{
	Init();

	std::cin >> N;

	int day, point;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> day >> point;
		result.push_back(std::make_pair(day, point));
	}

	std::sort(result.begin(), result.end());

	std::vector<std::pair<int, int>>::iterator cur = result.begin();

	while (cur != result.end())
	{
		assigment.push(cur->second);

		while (assigment.size() > cur->first)
		{
			assigment.pop();
		}

		cur++;
	}

	int tmp = 0;
	while (!assigment.empty())
	{
		tmp += assigment.top();
		assigment.pop();
	}

	std::cout << tmp;
}