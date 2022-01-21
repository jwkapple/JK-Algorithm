#include <iostream>
#include <vector>
#include <queue>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 1e9;

std::vector<pii> data;
std::vector<pii> Q;
int visit[MAX];
int n, N, M, a, b, size, result = 0;

int Calc(int L, int R, int num)
{
	if (L == R)
		return L;
	if (L + 1 == R)
	{
		int r = data[R].first;
		return num >= r ? R : L;
	}

	int mid = (L + R) / 2;

	if (data[mid].first >= num)
		return Calc(L, mid, num);
	else
		return Calc(mid + 1, R, num);
}

int presum(int value)
{
	int A = a + value;
	int B = b + value;

	if (B < 0 || A > n)
		return 0;

	if (A < 0)
		A = 0;
	if (B > n)
		B = n;

	int tmp = Calc(0, size - 1, A);

	A = data[tmp].second;
	B = data[Calc(0, size - 1, B)].second;

	tmp = visit[tmp] ? visit[tmp] : 0;
	return B - A + tmp;
}
int main()
{
	Init();

	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> a >> b;
		Q.push_back(pii(a, b));
		n = b;
	}

	std::cin >> M;

	int prev = 0;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> a >> b;
		prev += b;
		data.push_back(pii(a, prev));
		visit[a] = b;
	}

	size = data.size();

	std::cin >> a >> b;

	for (auto p : Q)
	{
		auto [X, value] = p;
		result += value * presum(X);
	}

	std::cout << result;
}