#include <iostream>
#include <vector>
#include <queue>
#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e4 + 1;

std::vector<pii> data[MAX];
int N, result = 0;

int func(int num)
{
	std::priority_queue<int> pq;
	int ret = 0;
	int tmp = 0;
	auto cur = data[num];

	int value;
	for (int i = 0; i < cur.size(); ++i)
	{
		auto [path, v] = cur[i];

		int value = func(path) + v;
		pq.push(value);

		tmp = tmp > value ? tmp : value;
	}

	if (pq.size() == 1)
	{
		ret = pq.top();
	}

	if (pq.size() >= 2)
	{
		ret += pq.top(); pq.pop();
		ret += pq.top();
	}

	result = result > ret ? result : ret;
	return tmp;
}
int main() {

	Init();

	std::cin >> N;

	int from, to, v;

	for (int i = 0; i < N - 1; ++i)
	{
		std::cin >> from >> to >> v;

		data[from].push_back(pii(to, v));
	}

	func(1);

	std::cout << result;
}