#include <iostream>
#include <algorithm>
#include <vector>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e5 + 1;
const int CUT = 1e6 + 1;

std::vector<int> path[MAX];
std::vector<pii> result;
int nodeNum[MAX];
int V, E, current = 1;

int func(int num, int parent)
{
	nodeNum[num] = current++;
	int value = nodeNum[num];

	int tmp;
	for (auto p : path[num])
	{
		if (p == parent) continue;

		if (!nodeNum[p])
		{
			int tmp = func(p, num);
			if (tmp > nodeNum[num])
			{
				result.push_back(pii(std::min(p, num), std::max(p, num)));
			}

			value = std::min(value, tmp);
		}
		else value = std::min(value, nodeNum[p]);
	}

	return value;
}
int main()
{
	Init();

	std::cin >> V >> E;

	int A, B;
	for (int i = 0; i < E; ++i)
	{
		std::cin >> A >> B;
		path[A].push_back(B);
		path[B].push_back(A);
	}

	func(1, 0);

	std::sort(result.begin(), result.end());
	std::cout << result.size() << "\n";
	for (auto p : result)
	{
		std::cout << p.first << " " << p.second << "\n";
	}
}
