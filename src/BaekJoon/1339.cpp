#include <iostream>
#include <string>
#include <algorithm>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

int data[26];
int N, result = 0;
int main()
{
	Init();
	std::cin >> N;

	int num = 9;
	std::string current;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> current;

		int v = 1;
		for (int j = current.size() - 1; j >= 0; --j)
		{
			data[current[j] - 'A'] += v;
			v *= 10;
		}
	}

	std::sort(data, data + 26);

	for (int i = 25; i >= 0; --i)
	{
		if (!data[i]) break;

		result += data[i] * num;
		num--;
	}

	std::cout << result;
}