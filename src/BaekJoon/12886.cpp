#include <iostream>
#include <queue>

#define pii std::pair<int, int>
void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1500 + 1;

std::queue<pii> Q;
bool visited[MAX][MAX], isDone = false;
int A, B, tot;

int main()
{
	Init();

	std::cin >> A >> B >> tot;

	tot += A + B;

	Q.push(pii(A, B));

	int tA, tB, c;
	while (!Q.empty() && !isDone)
	{
		auto[a, b] = Q.front(); Q.pop();

		if (a < 0 || b < 0) continue;

		c = tot - (a + b);
		if (a == b && b == c)
		{
			isDone = true;
			break;
		}

		auto& ret = visited[a][b];
		if (ret) continue;
		ret = true;

		if (a != b)
		{
			tA = a > b ? a - b : a + a;
			tB = a > b ? b + b : b - a;

			if (tA < 0 || tB < 0) continue;
			if (!visited[tA][tB]) Q.push(pii(tA, tB));
		}

		if (b != c)
		{
			tB = c > b ? b + b : b - c;

			if (tB < 0) continue;
			if (!visited[a][tB])Q.push(pii(a, tB));
		}

		if (a != c)
		{
			tA = a > c ? a - c : a + a;

			if (tA < 0) continue;
			if (!visited[tA][b]) Q.push(pii(tA, b));
		}
	}

	std::cout << isDone;
}