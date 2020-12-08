#include <iostream>
#include <climits>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e5 + 1;

int data[MAX];
int N, cur = 0;

int find(int left, int right, int value)
{
	if (left == right) return left;
	if (left + 1 == right)
	{
		if (data[left] < value) return right;
		else return left;
	}
	int mid = (left + right) / 2;

	if (value <= data[mid]) return find(left, mid, value);
	else return find(mid + 1, right, value);
}
int main()
{
	Init();

	std::cin >> N;

	data[0] = INT_MIN;

	int tmp;
	for (int i = 1; i <= N; ++i)
	{
		std::cin >> tmp;
		if (tmp > data[cur]) data[++cur] = tmp;
		else
		{
			data[find(0, cur, tmp)] = tmp;
		}
	}

	std::cout << N - cur;
}