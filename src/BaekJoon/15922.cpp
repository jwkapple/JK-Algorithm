#include <iostream>
#include <vector>
#include <queue>

#define pii std::pair<int, bool>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int IMP = 2e9;
std::priority_queue<pii, std::vector<pii>, std::greater<pii>> Q;
int N, start = IMP, online = 0;
long long result = 0;
int main()
{
	Init();

	std::cin >> N;

	int in, out;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> in >> out;

		Q.push(pii(in, true));
		Q.push(pii(out, false));
	}

	while (!Q.empty())
	{
		auto [point, value] = Q.top();
		Q.pop();

		if (start == IMP)
		{
			start = point;
		}

		if (value)
		{
			online++;
		}
		else
			online--;

		if (online == 0)
		{
			result += point - start;
			start = IMP;
		}
	}

	std::cout << result;
}