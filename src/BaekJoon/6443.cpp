#include <iostream>
#include <vector>
#include <string>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 26 + 1;

std::vector<std::string> data;
std::string line;

int stock[MAX], output[MAX];

int N, lSize;

void func(int cur)
{
	if (cur == lSize)
	{
		for (int i = 0; i < lSize; ++i)
		{
			std::cout << (char)('a' + output[i]);
		}

		std::cout << "\n";

		return;
	}

	for (int i = 0; i < MAX; ++i)
	{
		if (stock[i] != 0)
		{
			stock[i]--;
			output[cur] = i;
			func(cur + 1);
			stock[i]++;
		}
	}
}
int main()
{
	Init();

	std::cin >> N;

	std::string tmp;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> tmp;
		data.push_back(tmp);
	}

	for (auto p : data)
	{
		line = p;
		lSize = line.size();

		for (auto k : line)
		{
			stock[k - 'a']++;
		}

		func(0);
		for (int i = 0; i < MAX; ++i)
		{
			stock[i] = 0;
		}
	}
}