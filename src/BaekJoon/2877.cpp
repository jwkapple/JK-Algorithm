#include <iostream>
#include <vector>

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

std::vector<int> result;
int K;
int N = 0;

int main()
{
	Init();

	std::cin >> K;

	K += 1;

	while (K != 1)
	{
		result.push_back(K % 2);
		K /= 2;
	}

	for (int i = result.size() - 1;i >= 0; i--)
	{
		if (result[i] == 1) std::cout << 7;
		else std::cout << 4;
	}
}