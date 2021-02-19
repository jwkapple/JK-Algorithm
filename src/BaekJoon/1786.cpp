#include <iostream>
#include <string>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e7 + 1;

std::vector<int> result;
std::string S, W;
int fail[MAX];

int main()
{
	Init();

	std::getline(std::cin, S);
	std::getline(std::cin, W);

	int N = S.size();
	int M = W.size();

	for (int i = 1, j = 0; i < M; ++i)
	{
		while (j > 0 && W[i] != W[j]) j = fail[j - 1];

		if (W[i] == W[j]) fail[i] = ++j;
	}

	for (int i = 0, j = 0; i < N; ++i)
	{
		while (j > 0 && S[i] != W[j]) j = fail[j - 1];

		if (S[i] == W[j])
		{
			if (j == M - 1)
			{
				result.push_back(i - M + 2);
				j = fail[j];
			}
			else j++;
		}
	}

	std::cout << result.size() << "\n";
	for (int i = 0; i < result.size(); ++i)
	{
		std::cout << result[i] << " ";
	}
}