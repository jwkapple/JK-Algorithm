#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

std::vector<int> bag;
std::vector<std::pair<int, int>> jew;
int N, M;

int main()
{
	Init();

	std::cin >> N >> M;

	bag.resize(M);

	int w, v;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> w >> v;
		jew.push_back(std::make_pair(w, v));
	}

	for (int i = 0; i < M; ++i)
	{
		std::cin >> bag[i];
	}

	std::sort(bag.begin(), bag.end());
	std::sort(jew.begin(), jew.end());

	long long result = 0;
	std::priority_queue<int> Q;
	for (int i = 0, j = 0; i < M; ++i)
	{
		while (j < N && jew[j].first <= bag[i])
		{
			Q.push(jew[j++].second);
		}

		if (!Q.empty())
		{
			result += Q.top();
			Q.pop();
		}
	}

	std::cout << result;
}