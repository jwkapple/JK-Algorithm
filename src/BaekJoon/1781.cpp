#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

int N;

std::vector<std::pair<int, int>> data; // <dead, noodle>
int main()
{
	Init();

	std::cin >> N;

	int dead, noodle;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> dead >> noodle;
		data.push_back(std::make_pair(dead, noodle));
	}

	std::sort(data.begin(), data.end());

	long long result = 0;
	std::priority_queue<int> Q;

	for (int i = N, j = N; i >= 1; --i)
	{
		while (j > 0 && data[j - 1].first >= i)
		{
			Q.push(data[j-- - 1].second);
		}

		if (!Q.empty())
		{
			result += Q.top();
			Q.pop();
		}
	}

	std::cout << result;
}