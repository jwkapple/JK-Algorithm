#include <iostream>
#include <string>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

int N;
char C;
std::string data;

int main() {

	Init();

	std::cin >> data;
	N = data.length();
	C = data[N / 2];
	bool palindrome = true, tmp = true;

	for (int i = 0; i < N / 2; ++i)
	{
		if (C != data[i]) tmp = 0;
		if (data[i] != data[N - 1 - i])
		{
			palindrome = false;
			break;
		}
	}

	if (!palindrome) std::cout << N;
	else
	{
		if (tmp) std::cout << -1;
		else std::cout << N - 1;
	}
}