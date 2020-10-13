#include <iostream>

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e3 + 1;
int data[MAX];
int max[MAX];
int result = 0;
int N;

int main()
{
	Init();

	std::cin >> N;

	int tmp;
	for (int i = 1; i <= N; ++i)
	{
		std::cin >> tmp;
		data[i] = tmp;
		max[i] = tmp;

		int total = 0;
		for (int j = 1; j < i; ++j) { if (data[j] < data[i] && max[i] < max[j] + data[i]) max[i] = max[j] + data[i]; }
		if (result < max[i]) result = max[i];
	}

	std::cout << result;
}