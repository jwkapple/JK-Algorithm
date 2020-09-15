#include <iostream>
#include <vector>
#include <cmath>       

typedef long long ll;

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const ll MAX = 1 << 20;
int N, M, K;
std::vector<ll> result;
ll data[MAX * 2];

void update(ll A, ll B)
{
	data[A] = B;

	while (A > 1)
	{
		A /= 2;
		data[A] = data[A * 2] + data[A * 2 + 1];
	}
}

ll func(ll L, ll R, int node, int nodeL, int nodeR)
{

	if (R < nodeL || L > nodeR) return 0;
	if (node >= MAX) return data[node];
	if (L <= nodeL && R >= nodeR) return data[node];
	ll mid = (nodeL + nodeR) / 2;
	ll left = func(L, R, node * 2, nodeL, mid);
	ll right = func(L, R, node * 2 + 1, mid + 1, nodeR);
	return left + right;
}

int main()
{
	Init();

	std::cin >> N >> M >> K;

	int tmp;
	for (int i = 0;i < N; i++)
	{
		std::cin >> tmp;
		update(MAX + i, tmp);
	}

	int cnt;
	ll A, B;

	for (int i = 0;i < M + K; i++)
	{
		std::cin >> cnt >> A >> B;
		switch (cnt)
		{
		case 1:
			update(MAX + A - 1, B); break;
		case 2:
			result.push_back(func(A, B, 1, 1, MAX)); break;
		}
	}

	for (int i = 0;i < result.size(); i++)
	{
		std::cout << result[i] << "\n";
	}
}