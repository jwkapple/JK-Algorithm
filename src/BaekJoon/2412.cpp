#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define pii std::pair<int, int>
void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 1e5 + 1;

std::queue<int> Q;
std::vector<pii> Node;
bool visited[MAX];

int N, T;

bool calcX(int A, int B)
{
	int tmp = Node[B].first - Node[A].first;
	return (tmp >= -2 && tmp <= 2);
}
bool calcY(int A, int B)
{
	int tmp = Node[B].second - Node[A].second;
	return (tmp >= -2 && tmp <= 2);
}

pii func(int cur, int L, int R)
{
	if (L == R)
	{
		if (calcX(cur, L))
			return pii(L, L);
		else
			return pii(-1, -1);
	}

	int mid = (L + R) / 2;

	pii left = func(cur, L, mid);
	pii right = func(cur, mid + 1, R);

	if (left.first == -1 && right.first == -1)
		return pii(-1, -1);

	if (left.first == -1)
		return right;
	if (right.first == -1)
		return left;

	return pii(left.first, right.second);
}
int main()
{
	Init();

	std::cin >> N >> T;

	int a, b;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> a >> b;
		Node.push_back(pii(a, b));
	}

	Node.push_back(pii(0, 0));

	std::sort(Node.begin(), Node.end());

	Q.push(0);

	int size, value = 0;
	while (!Q.empty())
	{
		size = Q.size();

		for (int i = 0; i < size; ++i)
		{
			int cur = Q.front();
			Q.pop();

			if (Node[cur].second >= T)
			{
				std::cout << value;
				return 0;
			}

			if (visited[cur])
				continue;

			visited[cur] = true;

			auto [L, R] = func(cur, 0, N);

			if (L == -1)
				continue;
			for (int i = L; i <= R; ++i)
			{
				if (calcY(cur, i) && !visited[i])
					Q.push(i);
			}
		}

		value++;
	}

	std::cout << -1;
}