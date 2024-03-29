#include <iostream>
#include <vector>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e4 + 1;

std::vector<pii> data[MAX];
int N, max = 0;

int func(int num)
{
	if (data[num].empty()) return 0;

	int first = 0, second = 0;

	int pLong = 0;
	for (auto p : data[num])
	{
		auto [child, value] = p;
		pLong = func(child) + value;
		if (pLong > first) { second = first, first = pLong; continue; }
		if (pLong > second) { second = pLong; }
	}

	pLong = first + second;

	max = max > pLong ? max : pLong;

	return first;
}
int main()
{
	Init();

	std::cin >> N;

	int from, to, v;
	for (int i = 0; i < N - 1; ++i)
	{
		std::cin >> from >> to >> v;

		data[from].push_back(pii(to, v));
	}

	func(1);

	std::cout << max;
}