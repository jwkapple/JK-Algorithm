#include <iostream>
#include <queue>
#include <vector>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e5 + 2;
auto func = [](pii left, pii right)
{
	if (left.first != right.first)
		return left >= right;

	return left.second <= right.second;
};
std::priority_queue<pii, std::vector<pii>, decltype(func)> pq(func);
std::priority_queue<pii> current; // 높이, ID
std::vector<pii> result;
std::vector<int> data; // ID
bool visited[MAX]; // ID vaild 여부
int N;


int main() {

	Init();

	std::cin >> N;
	current.push(pii(0, 0));
	data.push_back(0);
	visited[0] = true;

	int from, to, v;
	for (int i = 1; i <= N; ++i)
	{
		std::cin >> from >> v >> to;
		data.push_back(v);
		pq.push(pii(from, i)), pq.push(pii(to, i * -1));
	}

	int x, id;
	while (!pq.empty())
	{
		x = pq.top().first;
		id = pq.top().second;
		pq.pop();

		while (!visited[current.top().second])
		{
			current.pop();
		}

		int value = current.top().first;

		if (id < 0)
		{
			id *= -1;

			visited[id] = false;

			while (!visited[current.top().second])
			{
				current.pop();
			}

			if (value != current.top().first) result.push_back(pii(x, current.top().first));

			continue;
		}

		current.push(pii(data[id], id));
		visited[id] = true;
		int cur = current.top().first;

		if (value != cur)
		{
			result.push_back(pii(x, cur));
		}
	}

	for (auto p : result)
	{
		std::cout << p.first << " " << p.second << " ";
	}
}