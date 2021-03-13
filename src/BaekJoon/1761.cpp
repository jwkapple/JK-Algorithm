#include <iostream>
#include <vector>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAXN = 17;
const int MAX = 4e4 + 2;

std::vector<pii> data[MAX];
std::vector<int> result;
int DP[MAX][MAXN], DPV[MAX][MAXN];
int depth[MAX];
int N, M;

void makeDepth(int num, int dep, int Parent)
{
	auto cur = data[num];

	depth[num] = dep;
	DP[num][0] = Parent;

	for (auto p : cur)
	{
		auto [path, v] = p;

		if (depth[path]) continue;

		DPV[path][0] = v;

		makeDepth(path, dep + 1, num);
	}
}

void first(int& x, int X, int& num)
{
	for (int j = MAXN - 1; j >= 0; --j)
	{
		if (X >= 1 << j)
		{
			X -= 1 << j;
			num += DPV[x][j];
			x = DP[x][j];
		}
	}
}
int func(int A, int B)
{
	int ret = 0;
	int depthA = depth[A], depthB = depth[B];

	if (depthA < depthB) first(B, depthB - depthA, ret);
	else
	{
		if (depthA > depthB) first(A, depthA - depthB, ret);
	}

	if (A == B) return ret;

	for (int i = MAXN - 1; i >= 0; --i)
	{
		if (DP[A][i] != 1 && DP[A][i] != DP[B][i])
		{
			ret += DPV[A][i] + DPV[B][i];

			A = DP[A][i];
			B = DP[B][i];
		}
	}

	return ret + DPV[A][0] + DPV[B][0];
}

int main() {

	Init();

	std::cin >> N;

	int from, to, v;
	for (int i = 0; i < N - 1; ++i)
	{
		std::cin >> from >> to >> v;

		data[from].push_back(pii(to, v));
		data[to].push_back(pii(from, v));
	}

	makeDepth(1, 1, 1);
	DP[1][0] = 0;
	for (int i = 1; i < MAXN; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			DP[j][i] = DP[DP[j][i - 1]][i - 1];
			DPV[j][i] = DPV[DP[j][i - 1]][i - 1] + DPV[j][i - 1];
		}
	}

	std::cin >> M;

	for (int i = 0; i < M; ++i)
	{
		std::cin >> from >> to;

		result.push_back(func(from, to));
	}

	for (auto p : result)
	{
		std::cout << p << "\n";
	}
}