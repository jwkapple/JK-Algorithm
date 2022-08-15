#include <iostream>
#include <queue>
#include <vector>

#define ll long long

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 1000 + 1;

std::priority_queue<ll, std::vector<ll>, std::greater<ll>> Q;
int N, M;

int main()
{
	Init();

	std::cin >> N >> M;

	int tmp;
	for (int i = 1; i <= N; ++i)
	{
		std::cin >> tmp;
		Q.push(tmp);
	}

	ll A, B, C;
	while (M--)
	{
		A = Q.top();
		Q.pop();
		B = Q.top();
		Q.pop();
		C = A + B;

		Q.push(C);
		Q.push(C);
	}

	ll result = 0;
	while (!Q.empty())
	{
		result += Q.top();
		Q.pop();
	}

	std::cout << result;
}