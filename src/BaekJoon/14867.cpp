#include <iostream>
#include <queue>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 1e4 + 1;

std::queue<pii> Q;
bool visited[MAX][MAX];

int a, b, finalA, finalB, result = 0;

int func(int A, int B)
{
	Q.push(pii(A, B));

	visited[A][B] = true;

	while (!Q.empty())
	{
		int size = Q.size();

		for (int i = 0; i < size; ++i)
		{
			auto [tA, tB] = Q.front();
			Q.pop();

			if (tA == finalA && tB == finalB)
				return result;

			int tmp, tmpA, tmpB;

			if (tA != 0)
			{
				if (!visited[0][tB])
				{
					visited[0][tB] = true;
					Q.push(pii(0, tB)); // EmptyA
				}
				tmp = b - tB;

				tmpA = tmp >= tA ? 0 : tA - tmp;
				tmpB = tmp >= tA ? tA + tB : b;

				if (!visited[tmpA][tmpB])
				{
					visited[tmpA][tmpB] = true;
					Q.push(pii(tmpA, tmpB)); // Swap A to B
				}
			}

			if (tB != 0)
			{
				if (!visited[tA][0])
					Q.push(pii(tA, 0)); // EmptyB

				tmp = a - tA;

				tmpA = tmp >= tB ? tA + tB : a;
				tmpB = tmp >= tB ? 0 : tB - tmp;

				if (!visited[tmpA][tmpB])
				{
					visited[tmpA][tmpB] = true;
					Q.push(pii(tmpA, tmpB)); // Swap B to A
				}
			}

			if (!visited[a][tB])
			{
				visited[a][tB] = true;
				Q.push(pii(a, tB)); // FillA
			}
			if (!visited[tA][b])
			{
				visited[tA][b] = true;
				Q.push(pii(tA, b)); // FillB
			}
		}

		result++;
	}

	return -1;
}
int main()
{
	Init();

	std::cin >> a >> b >> finalA >> finalB;

	if (b % a == 0)
	{
	}
	std::cout << func(0, 0);
}