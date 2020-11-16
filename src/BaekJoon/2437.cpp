#include <iostream>
#include <algorithm>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1001;

int data[MAX];
int N, result = 0;

int main()
{
	Init();

	std::cin >> N;

	for (int i = 0; i < N; ++i) std::cin >> data[i];

	std::sort(data, data + N);

	int cur = 0;
	int max = 1;
	while (!result)
	{
		int current = data[cur];
		if (current > max) { result = max; continue; }

		max += current;
		cur++;
	}

	std::cout << result;
}