#include <iostream>
#include <vector>
#include <string>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e7 + 2;

std::vector<int> result;
std::string data;
int fail[MAX];

int main()
{
	Init();

	data = 'a';

	while (data != ".")
	{
		std::getline(std::cin, data);
		if (data == ".") break;

		int N = data.size();
		int j = 0;
		for (int i = 1; i < N; ++i)
		{
			fail[i] = 0;
			if (j > 0 && data[i] != data[j]) j = fail[j - 1];
			if (data[i] == data[j]) fail[i] = ++j;
		}

		if (N % (N - fail[N - 1])) result.push_back(1);
		else result.push_back(N / (N - fail[N - 1]));
	}

	for (auto p : result)
	{
		std::cout << p << "\n";
	}
}