#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 100 + 1;

std::string A, B, C;
int LCS[MAX][MAX][MAX];

int main()
{
	Init();

	std::cin >> A >> B >> C;

	int AL = A.length(), BL = B.length(), CL = C.length();

	for (int a = 0; a < AL; ++a)
	{
		for (int b = 0; b < BL; ++b)
		{
			for (int c = 0; c < CL; ++c)
			{
				auto& current = LCS[a + 1][b + 1][c + 1];
				if (A[a] == B[b] && A[a] == C[c] && B[b] == C[c])
					current = LCS[a][b][c] + 1;
				else
				{
					current = std::max(LCS[a][b + 1][c + 1], LCS[a + 1][b][c + 1]);
					current = std::max(current, LCS[a + 1][b + 1][c]);
				}
			}
		}
	}

	std::cout << LCS[AL][BL][CL];
}