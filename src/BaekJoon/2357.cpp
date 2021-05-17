#include <iostream>
#include <vector>

#define pii std::pair<int, int>
void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1 << 17;

std::vector<pii> result;
int max[MAX * 2], min[MAX * 2];
int N, M, cur = 0;

void insert(int num)
{
	int current = MAX + cur;

	max[current] = num;

	int asc, tmp;
	while (current > 1)
	{
		asc = current / 2;
		if (max[asc] < max[current])
		{
			max[asc] = max[current];
			current /= 2;
		}
		else break;
	}

	current = MAX + cur++;

	min[current] = num;

	while (current > 1)
	{
		asc = current / 2;

		if (min[asc] > min[current] || min[asc] == 0)
		{
			min[asc] = min[current];
			current /= 2;
		}
		else break;
	}
}

int findMax(int L, int R, int from, int to, int num)
{
	if (L >= from && R <= to) return max[num];

	if (L > to || R < from) return -1;

	int mid = (L + R) / 2;

	int left = findMax(L, mid, from, to, num * 2);
	int right = findMax(mid + 1, R, from, to, num * 2 + 1);

	if (left == -1) return right;
	if (right == -1) return left;

	return left > right ? left : right;
}

int findMin(int L, int R, int from, int to, int num)
{
	if (L >= from && R <= to) return min[num];

	if (L > to || R < from) return -1;

	int mid = (L + R) / 2;

	int left = findMin(L, mid, from, to, num * 2);
	int right = findMin(mid + 1, R, from, to, num * 2 + 1);

	if (left == -1) return right;
	if (right == -1) return left;

	return left < right ? left : right;
}

int main()
{
	Init();

	std::cin >> N >> M;;

	int tmp;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> tmp;

		insert(tmp);
	}

	int from, to, minV, maxV;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> from >> to;

		maxV = findMax(1, MAX, from, to, 1);
		minV = findMin(1, MAX, from, to, 1);

		result.push_back(pii(minV, maxV));
	}

	for (auto p : result)
	{
		std::cout << p.first << " " << p.second << "\n";
	}
}