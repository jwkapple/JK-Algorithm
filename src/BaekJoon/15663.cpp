#include <iostream>
#include <algorithm>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

std::vector<int> data, result;
bool visited[8 + 1];
int N, M;

void func(int cur)
{
	int prev = 0;
	if (cur == M)
	{
		for (auto p : result)
		{
			std::cout << data[p] << " ";
		}

		std::cout << "\n";
		return;
	}

	for (int i = 0; i < data.size(); ++i)
	{
		if (!visited[i])
		{
			if (prev == data[i])
				continue;

			visited[i] = true;
			result.push_back(i);
			func(cur + 1);
			visited[i] = false;
			result.pop_back();

			prev = data[i];
		}
	}
}
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

	func(0);
}