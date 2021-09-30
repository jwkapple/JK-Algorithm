#include <iostream>

const int MAX = 21;

int data[MAX];
int N, S;
int result = 0;
int currentSum = 0;

void back(int current)
{
	if (current == N) return;
	if (currentSum + data[current] == S) result++;

	back(current + 1);

	currentSum += data[current];

	back(current + 1);

	currentSum -= data[current];
}
int main()
{
	std::cin >> N >> S;

	for (int i = 0; i < N; i++)
	{
		std::cin >> data[i];
	}

	back(0);

	std::cout << result;
}