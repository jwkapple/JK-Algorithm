#include <iostream>
#include <algorithm>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 8 + 1;

std::vector<int> data;
int N, result = 0;

int main()
{
	Init();

	std::cin >> N;

	int tmp;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> tmp;
		data.push_back(tmp);
	}

	std::sort(data.begin(), data.end());

	int left = 0, right = N - 1;

	tmp = N / 2;

	for (int i = 0; i < tmp; ++i)
	{
		result += data[right] - data[left++];
		result += data[right--] - data[left];
	}

	std::cout << result;
}