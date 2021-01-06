#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e5 + 1;

int A[MAX], B[MAX], LIS[MAX];
int cur = 0;
int N;

int find(int from, int to, int num)
{
	if (from == to) return from;
	if (from + 1 == to)
	{
		if (LIS[from] > num) return from;
		else return to;
	}

	int mid = (from + to) / 2;

	if (LIS[mid] > num) return find(from, mid, num);
	else return find(mid + 1, to, num);
}
int main()
{
	Init();

	LIS[0] = -1;
	std::cin >> N;

	int tmp;
	for (int i = 0; i < N; ++i) std::cin >> A[i];
	for (int i = 0; i < N; ++i)
	{
		std::cin >> tmp;
		B[tmp] = i;
	}

	for (int i = 0; i < N; ++i)
	{
		int current = B[A[i]];
		if (LIS[cur] < current) LIS[++cur] = current;
		else
		{
			LIS[find(0, cur, current)] = current;
		}
	}

	std::cout << cur;
}