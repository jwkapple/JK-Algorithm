#include <iostream>
#include <vector>
#include <climits>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e7 + 2;

std::vector<int> result;
std::vector<pii> path;
int LIS[MAX];
int data[MAX];
int N, cur = 0;

int find(int from, int to, int n)
{
	if (from == to) return from;
	if (from + 1 == to)
	{
		if (LIS[from] < n) return to;
		else return from;
	}

	int mid = (from + to) / 2;
	if (LIS[mid] >= n) return find(from, mid, n);
	else return find(mid + 1, to, n);
}
int main()
{
	Init();

	std::cin >> N;

	LIS[0] = INT_MIN;


	for (int i = 0; i < N; ++i)
	{
		std::cin >> data[i];
	}

	for (int i = 0; i < N; ++i)
	{
		if (LIS[cur] < data[i])
		{
			LIS[++cur] = data[i];
			path.push_back(pii(cur, data[i]));
		}
		else
		{
			int tmp = find(0, cur, data[i]);
			LIS[tmp] = data[i];
			path.push_back(pii(tmp, data[i]));
		}
	}

	for (int i = N - 1; i >= 0; --i)
	{
		if (path[i].first == cur)
		{
			result.push_back(path[i].second);
			cur--;
		}
	}

	std::cout << result.size() << "\n";
	for (int i = result.size() - 1; i >= 0; --i)
	{
		std::cout << result[i] << " ";
	}

	std::cout << "\n";
}