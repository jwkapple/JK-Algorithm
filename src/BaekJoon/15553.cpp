#include <iostream>
#include <algorithm>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

std::vector<int> data;
int N, K;

int main()
{
	Init();

	std::cin >> N >> K;

	int start, end;
	int tmp, prev = 0;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> tmp;

		if (i == 0)
		{
			prev = tmp;
			start = tmp;
		}

		data.push_back(tmp - prev);

		prev = tmp;
	}

	end = tmp;

	int total = end - start + 1;

	total += K - 1;
	std::sort(data.begin(), data.end());

	int size = data.size() - 1;
	for (int i = 0; i < K - 1; ++i)
	{
		total -= data[size - i];
	}

	std::cout << total;
}