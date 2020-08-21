#include <iostream>

const int MAX = 1e6 + 1;

int A[MAX];
int B[MAX];
int result[MAX * 2];

int N, M;

int main()
{
	std::ios_base::sync_with_stdio(false);

	std::cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		std::cin >> A[i];
	}

	for (int i = 0; i < M; i++)
	{
		std::cin >> B[i];
	}

	int a = 0, b = 0;
	int r = 0;

	while (a < N && b < M)
	{
		if (A[a] < B[b])
		{
			result[r++] = A[a++];
		}

		else
		{
			result[r++] = B[b++];
		}
	}

	while (a < N)
	{
		result[r++] = A[a++];
	}

	while (b < M)
	{
		result[r++] = B[b++];
	}

	for (int i = 0; i < r; i++)
	{
		std::cout << result[i] << " ";
	}

}
