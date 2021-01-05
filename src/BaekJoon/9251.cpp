#include <iostream>
#include <string>
#include <algorithm>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e3 + 1;

std::string A, B;
int LCS[MAX][MAX];
int main()
{
	Init();
	std::cin >> A >> B;

	int AL = A.length(), BL = B.length();
	for (int a = 0; a < AL; ++a)
	{
		for (int b = 0; b < BL; ++b)
		{
			if (A[a] == B[b]) LCS[a + 1][b + 1] = LCS[a][b] + 1;
			else LCS[a + 1][b + 1] = std::max(LCS[a][b + 1], LCS[a + 1][b]);
		}
	}

	std::cout << LCS[AL][BL];
}