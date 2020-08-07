#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int L, P, V;

	std::vector<int> result;
	int caseNum = 1;
	while (true)
	{
		int vacation = 0;

		std::cin >> L >> P >> V;

		if (L == 0 && P == 0 && V == 0) break;

		int staticCost = (V / P);

		vacation += staticCost * L;

		vacation += std::min(L, V - P * staticCost);

		result.push_back(vacation);
	}

	for (int i = 0; i < result.size(); i++)
	{
		std::cout << "Case " << i + 1 << ": " << result[i] << "\n";
	}
}