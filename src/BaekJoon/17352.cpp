#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 3e5 + 1;

int parent[MAX];
int N;

int find(int A)
{
	if (parent[A] == A)
		return A;

	return parent[A] = find(parent[A]);
}

void merge(int A, int B)
{
	A = find(A);
	B = find(B);

	if (A == B)
		return;

	if (A > B)
		parent[A] = B;
	else
		parent[B] = A;

	return;
}

int main()
{
	Init();

	std::cin >> N;

	int from, to;

	for (int i = 1; i <= N; ++i)
	{
		parent[i] = i;
	}

	for (int i = 0; i < N - 2; ++i)
	{
		std::cin >> from >> to;

		merge(from, to);
	}

	int result;

	for (int i = 2; i <= N; ++i)
	{
		if (find(i) != 1)
		{
			result = i;
			break;
		}
	}

	std::cout << 1 << " " << result;
}