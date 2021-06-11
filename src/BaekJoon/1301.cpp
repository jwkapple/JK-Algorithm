#include <iostream>
#include <cstring>

#define ll long long

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 10 + 1;

ll DP[MAX][MAX][MAX][MAX][MAX][5][5], result = 0;
int data[5];
int N;

ll func(int a, int b)
{
	ll& cur = DP[data[0]][data[1]][data[2]][data[3]][data[4]][a][b];
	if (cur != -1) return cur;
	else if (data[0] + data[1] + data[2] + data[3] + data[4] == 0) return 1;
	else
	{
		cur = 0;
		for (int i = 0;i < N;i++)
		{
			if (data[i] == 0) continue;
			if (a == i || b == i) continue;
			else
			{
				data[i]--;
				cur += func(b, i);
				data[i]++;
			}
		}
		return cur;
	}
	return 0;
}

int main()
{
	Init();

	std::cin >> N;

	for (int i = 0;i < N;i++) { std::cin >> data[i]; }

	std::memset(DP, -1, sizeof(DP));

	for (int a = 0;a < N;a++)
	{
		for (int b = 0;b < N;b++)
		{
			if (a == b) continue;
			else
			{
				data[a]--; data[b]--;
				result += func(a, b);
				data[a]++; data[b]++;
			}
		}
	}
	std::cout << result;
}