#include <iostream>
#include <algorithm>
#include <vector>
#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e5 + 1;
std::vector<pii> data;
int L[MAX], R[MAX];
int N, K;

int main()
{
	Init();

	std::cin >> N >> K;

	data.push_back(pii(0, 0));
	int W, V;
	for (int i = 1; i <= N; ++i)
	{
		std::cin >> W >> V;
		data.push_back(pii(W, V));
	}

	std::sort(data.begin(), data.end());

	int l, r;
	int* left;
	int* right;
	for (int y = 1; y <= N; ++y)
	{
		if (y % 2) { left = L, right = R; }
		else { left = R, right = L; }

		auto[weight, value] = data[y];

		for (int x = 1; x <= K; ++x)
		{
			if (x < weight) left[x] = right[x];
			else
			{
				l = right[x - weight] + value;
				r = right[x];

				left[x] = l > r ? l : r;
			}
		}
	}

	if (N % 2) std::cout << L[K];
	else std::cout << R[K];
}