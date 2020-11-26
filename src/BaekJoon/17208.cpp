#include <iostream>
#include <algorithm>

#define pii std::pair<int, int>
void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 101;

int dp[MAX][301][301];
pii order[MAX];
int N, M, K;

int back(int ord, int CB, int FF)
{
	if (CB <= 0 || FF <= 0 || ord == N) return 0;
	if (dp[ord][CB][FF]) return dp[ord][CB][FF];
	if (order[ord].first <= CB && order[ord].second <= FF)
	{
		return dp[ord][CB][FF] = std::max(1 + back(ord + 1, CB - order[ord].first, FF - order[ord].second), back(ord + 1, CB, FF));
	}
	else return dp[ord][CB][FF] = back(ord + 1, CB, FF);
}

int main()
{
	Init();

	std::cin >> N >> M >> K;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> order[i].first >> order[i].second;
	}

	std::cout << back(0, M, K);
}