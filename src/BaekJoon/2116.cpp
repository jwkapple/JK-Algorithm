#include <iostream>
#include <algorithm>
#include <vector>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e4 + 1;

std::vector<pii> max[MAX];
int data[MAX][7], dice[MAX][7], tmp[MAX], tmp2[MAX];
int N, result = 0, no1, no2;

int func(int face, int num)
{
	if (num == N + 1) return 0;

	int cur = 0;

	face = dice[num][face];

	tmp2[num] = face;
	switch (face)
	{
	case 1: no1 = 1, no2 = 6; break;
	case 6: no1 = 6, no2 = 1; break;
	case 2: no1 = 2, no2 = 4; break;
	case 4: no1 = 4, no2 = 2; break;
	case 3: no1 = 3, no2 = 5; break;
	case 5: no1 = 5, no2 = 3; break;
	}

	for (int i = 0; i < 6; ++i)
	{
		auto[v, n] = max[num][i];

		if (n == no1 || n == no2) continue;

		cur = v; break;
	}

	tmp[num] = cur;
	return cur + func(data[num][no2], num + 1);
}

int main()
{
	Init();

	std::cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= 6; ++j)
		{
			std::cin >> data[i][j];
			dice[i][data[i][j]] = j;
			max[i].push_back(pii(data[i][j], j));
		}

		std::sort(max[i].begin(), max[i].end(), [](pii L, pii R)
		{
			return L.first > R.first;
		});
	}

	int A;
	for (int i = 1; i <= 6; ++i)
	{
		A = func(data[1][i], 1);
		result = result > A ? result : A;
	}

	std::cout << result;
}