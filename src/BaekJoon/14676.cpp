#include <iostream>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e5 + 1;

std::vector<int> pri[MAX];
int data[MAX];
int available[MAX];
int build[MAX];
int N, M, K;

bool check(int a, int b)
{
	switch (a)
	{
	case 1: {
		if (!available[b]) return false;

		build[b]++;
		for (int i = 0; i < pri[b].size(); ++i) { available[pri[b][i]]++; }
		break;
	}

	case 2:
	{
		if (!build[b]) return false;

		if (!(--build[b])) for (int i = 0; i < pri[b].size(); ++i) { available[pri[b][i]]--; }
		break;
	}
	}

	return true;
}

int main()
{
	Init();

	std::cin >> N >> M >> K;

	int a, b;
	for (int i = 0;i < M; ++i)
	{
		std::cin >> a >> b;
		pri[a].push_back(b);
		data[b]++;
	}

	for (int i = 1; i <= N; ++i) if (!data[i]) available[i]++;
	for (int i = 0; i < K; ++i)
	{
		std::cin >> a >> b;
		if (!check(a, b)) { std::cout << "Lier!"; return 0; }
	}

	std::cout << "King-God-Emperor";
}