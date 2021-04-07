#include <iostream>
#include <string>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 5e5;

int data[MAX], result[MAX];

int N, M, current = 0;
int main()
{
	Init();

	std::cin >> N >> M;

	std::string tmp;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> tmp;
		for (auto p : tmp)
		{
			data[i] |= 1 << (p - 'a');
		}
	}

	int a; char b;
	for (int i = 0; i < M; ++i)
	{
		int total = 0;
		std::cin >> a >> b;

		if (a == 1) current |= 1 << (b - 'a');
		else current &= ~(1 << (b - 'a'));

		for (int j = 0; j < N; ++j)
		{
			if (!(data[j] & current)) total++;
		}

		result[i] = total;
	}

	for (int i = 0; i < M; ++i)
	{
		std::cout << result[i] << "\n";
	}
}