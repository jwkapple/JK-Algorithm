#include <iostream>
#include <vector>
#include <queue>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e9 + 1;
std::priority_queue<pii, std::vector<pii>, std::less<pii>> pq;
int N, DL = MAX;

int main()
{
	Init();

	std::cin >> N;

	int d, t;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> d >> t;

		pq.push(pii(t, d));
	}

	while (!pq.empty())
	{
		auto[T, D] = pq.top(); pq.pop();

		DL = DL > T ? T : DL;
		DL -= D;
	}

	std::cout << DL;
}