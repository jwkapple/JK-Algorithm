#include <iostream>
#include <climits>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

struct Node
{
	int Num;
	int Left;
	int Right;

	void init(int n, int l, int r) { Num = n; Left = l; Right = r; };

};
const int MAX = 1e4 + 2;
std::pair<int, int> width[MAX]; // <min, max>

int mode[MAX];
Node data[MAX];
int N, L = 1, wid = 1;

void func(int cur, int level)
{
	L = level > L ? level : L;

	if (data[cur].Left != -1) func(data[cur].Left, level + 1);

	if (!width[level].first) { width[level].first = INT_MAX; width[level].second = INT_MIN; }

	if (width[level].first > wid) width[level].first = wid;
	if (width[level].second < wid) width[level].second = wid;

	wid++;

	if (data[cur].Right != -1) func(data[cur].Right, level + 1);
}
int main()
{
	Init();

	std::cin >> N;

	int num, left, right;
	for (int i = 1; i <= N; ++i)
	{
		std::cin >> num >> left >> right;
		mode[left]++; mode[right]++;
		data[num].init(num, left, right);
	}

	int start = 0;
	for (int i = 1; i <= N; ++i) { if (!mode[i]) start = i; }
	func(start, 1);

	int maxNum, max = 0;
	for (int i = 1; i <= L; ++i)
	{
		int current = width[i].second - width[i].first + 1;
		if (max < current) { max = current; maxNum = i; }
	}

	std::cout << maxNum << " " << max;
}