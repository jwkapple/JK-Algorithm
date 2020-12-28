#include <iostream>
#include <vector>

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e4 + 5;

std::vector<int> result;
int N, K, T;

int func(int from, int to, int num, int data[MAX])
{
	if (from == to) return from;
	if (from + 1 == to)
	{
		if (data[from] >= num) return from;
		else return to;
	}

	int mid = (from + to) / 2;

	if (data[mid] >= num) return func(from, mid, num, data);
	else return func(mid + 1, to, num, data);
}
int main()
{
	Init();

	std::cin >> T;

	while (T--)
	{
		int data[MAX];
		data[0] = -1;
		std::cin >> N >> K;

		int tmp, cur = 0;
		for (int i = 0; i < N; ++i)
		{
			std::cin >> tmp;

			if (data[cur] < tmp) data[++cur] = tmp;
			else data[func(0, cur, tmp, data)] = tmp;
		}

		if (cur >= K) result.push_back(1);
		else result.push_back(0);
	}

	for (int i = 0; i < result.size(); ++i)
	{
		std::cout << "Case #" << i + 1 << "\n";
		std::cout << result[i] << "\n";
	}
}