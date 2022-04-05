#include <iostream>
#include <string>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e7 + 1;

std::string S;
int N, fail[MAX];

int main()
{
	Init();

	std::cin >> N >> S;

	for (int i = 1, j = 0; i < N; ++i)
	{
		if (j > 0 && S[i] != S[j]) j = fail[j - 1];

		if (S[i] == S[j]) fail[i] = ++j;
	}

	if (!fail[N - 1]) std::cout << N;
	else std::cout << N - fail[N - 1];
}