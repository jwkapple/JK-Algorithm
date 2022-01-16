#include <iostream>
#include <algorithm>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 1e5 + 1;

std::vector<int> data;
int N, M, result = 2e9 + 1, left = 0, right = 0;

int main()
{
	Init();

	std::cin >> N >> M;

	int tmp;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> tmp;
		data.push_back(tmp);
	}

	std::sort(data.begin(), data.end());

	int size = data.size() - 1, diff;
	while (left <= size && right <= size)
	{
		diff = data[right] - data[left];
		if (diff >= M)
		{
			result = result > diff ? diff : result;
			left++;
		}
		else
		{
			right++;
		}
	}

	std::cout << result;
}