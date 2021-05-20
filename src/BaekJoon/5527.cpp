#include <iostream>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

std::vector<int> data;
int N, result = 0;
int main()
{
	Init();

	std::cin >> N;

	data.push_back(0);
	int start = 0;
	bool prev, cur;

	std::cin >> prev;

	for (int i = 1; i < N; ++i)
	{
		std::cin >> cur;

		if (cur == prev)
		{
			data.push_back(i - start);
			start = i;
		}

		prev = cur;
	}

	data.push_back(N - start);
	data.push_back(0);

	int Prev = 0;
	int Cur = data[1];
	int size = data.size() - 1;
	for (int i = 1; i < size; ++i)
	{
		Cur += data[i + 1];
		result = result > Cur ? result : Cur;
		Cur -= Prev;
		Prev = data[i];
	}

	std::cout << result;
}