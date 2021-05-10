#include <iostream>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

enum class Case { MEM, PARTY };
const int MAX = 50 + 1;

bool truth[MAX], bParty[MAX];
std::vector<int> member[MAX], party[MAX], data;
int N, M, T, result = 0;

void func(int num);
void P(int num);

void func(int num)
{
	if (truth[num]) return;

	truth[num] = true;

	for (auto p : member[num]) { P(p); }
}
void P(int num)
{
	if (bParty[num]) return;

	bParty[num] = true;

	for (auto p : party[num]) { func(p); }
}
int main()
{
	Init();

	std::cin >> N >> M >> T;

	int tmp;
	for (int i = 0; i < T; ++i)
	{
		std::cin >> tmp;
		data.push_back(tmp);
	}

	int num;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> num;
		for (int j = 0; j < num; ++j)
		{
			std::cin >> tmp;
			member[tmp].push_back(i);
			party[i].push_back(tmp);
		}
	}

	for (auto p : data) { func(p); }
	for (int i = 0; i < M; ++i) { if (!bParty[i]) result++; }

	std::cout << result;
}