#include <iostream>
#include <cmath>

const int MAX = 1e6 + 1;
int A, P;
unsigned long visited[MAX];
unsigned long result;
unsigned long current = 0;
void func(int num)
{
	unsigned long sum = 0;
	unsigned long upper = 10;
	if (visited[num] != -1)
	{
		result = visited[num];
		return;
	}

	visited[num] = current;
	while (true)
	{
		sum += std::pow((num % upper), P);
		num /= 10;

		if (num / upper == 0)
		{
			sum += std::pow((num % upper), P);
			break;
		}
	}

	current++;
	func(sum);
}

int main()
{
	std::cin >> A >> P;

	for (int i = 0;i < MAX; i++)
	{
		visited[i] = -1;
	}
	func(A);

	std::cout << result;
}