#include <iostream>
#include <vector>
#include <queue>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

struct Node
{
	int Origin;
	int Data;

	Node(int o, int d) : Origin(o), Data(d) {};
};

bool operator>(const Node& right, const Node& left)
{
	if (right.Data == left.Data) return right.Origin > left.Origin;
	else return right.Data > left.Data;
}

const int MAX = 1e5 + 1;

std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;
std::vector<int> result;
int N;

void insert(int num)
{
	int d;
	if (num < 0) d = num * -1;
	else d = num;

	pq.push(Node(num, d));
}

int pop()
{
	if (pq.empty()) return 0;
	else
	{
		int ret = pq.top().Origin; pq.pop(); return ret;
	}
}
int main()
{
	Init();

	std::cin >> N;

	int tmp;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> tmp;

		if (!tmp) result.push_back(pop());
		else insert(tmp);
	}

	for (int i = 0; i < result.size(); ++i)
	{
		std::cout << result[i] << "\n";
	}
}