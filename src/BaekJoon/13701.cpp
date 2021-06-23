#include <iostream>
#include <bitset>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1 << 25;

std::bitset<MAX> data;
int N;

int main()
{

	Init();

	while (scanf("%d", &N) != EOF)
	{
		if (!data[N])
		{
			data[N] = 1;
			printf("%d", N);
		}
	}
}