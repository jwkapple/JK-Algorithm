#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e3 + 1;

std::vector<char> result;
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

	int a = AL, b = BL;
	while (true)
	{
		if (!LCS[a][b]) break;

		if (A[a - 1] == B[b - 1])
		{
			result.push_back(A[a - 1]);
			a--; b--;
		}
		else
		{
			if (LCS[a][b] == LCS[a - 1][b]) a--;
			else b--;
		}
	}

	std::cout << LCS[AL][BL] << "\n";

	for (int i = result.size() - 1; i >= 0; i--)
	{
		std::cout << result[i];
	}
}