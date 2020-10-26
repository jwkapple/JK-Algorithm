#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e4 + 1;

std::queue<int> Q;
bool visited[MAX];
int N, cnt = 0;
int dp[MAX];
int time[MAX];
int result = 0;
int prep[MAX]; // 간선 갯수
std::vector<int> work[MAX]; // 선행 임무
std::vector<int> work2[MAX];

int main()
{
	Init();

	std::cin >> N;

	std::fill(dp, dp + N + 1, -1);

	int tmp;
	for (int i = 1; i <= N; ++i)
	{
		std::cin >> time[i] >> prep[i];
		tmp = prep[i];
		while (tmp--)
		{
			int tmp2;
			std::cin >> tmp2;
			work[tmp2].push_back(i);
			work2[i].push_back(tmp2);
		}
	}

	while (cnt != N)
	{
		for (int i = 1; i <= N; ++i)
		{
			if (prep[i] == 0 && !visited[i]) { Q.push(i); cnt++; visited[i] = true; }
		}

		while (!Q.empty())
		{
			int cur = Q.front(); Q.pop();

			int max = 0;

			for (int i = 0; i < work[cur].size(); ++i) { prep[work[cur][i]]--; }
			for (int i = 0; i < work2[cur].size(); ++i) { max = std::max(max, dp[work2[cur][i]]); }
			dp[cur] = max + time[cur];
			result = std::max(result, dp[cur]);
		}
	}

	std::cout << result;
}