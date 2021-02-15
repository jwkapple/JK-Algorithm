#include <iostream>
#include <string>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

std::string sen;
int data[4];
int N, result = 0;
char R;

int main()
{
	Init();

	std::cin >> N;

	std::cin >> sen;

	for (int i = 0; i < N; ++i)
	{
		switch (sen[i])
		{
		case 'G': data[0]++; break;
		case 'C': data[1]++; break;
		case 'A': data[2]++; break;
		case 'T': data[3]++; break;
		}
	}

	int min = data[0] > data[1] ? data[1] : data[0];
	min = min > data[2] ? data[2] : min;
	min = min > data[3] ? data[3] : min;

	result = min;

	if (data[0] == min) R = 'G';
	if (data[1] == min) R = 'C';
	if (data[2] == min) R = 'A';
	if (data[3] == min) R = 'T';

	std::cout << result << "\n";
	for (int i = 0; i < N; ++i)
	{
		std::cout << R;
	}
}