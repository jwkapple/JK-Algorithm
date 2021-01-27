#include <iostream>
#include <algorithm>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

struct Node
{
	int From;
	int To;
	int Value;
};

bool func(Node left, Node right)
{
	if (left.To < right.To) return true;

	else if (left.To == right.To)
	{
		if (left.From < right.From) return true;
	}

	return false;
}

const int MAX = 1e4 + 1;
Node data[MAX];
int Box[MAX];
int N, C, M, result = 0;

int main()
{
	Init();

	std::cin >> N >> C >> M;

	for (int i = 0; i < M; ++i)
	{
		std::cin >> data[i].From >> data[i].To >> data[i].Value;
	}

	std::sort(data, data + M, func);

	for (int i = 0; i < M; ++i)
	{
		int box = 0;
		for (int j = data[i].From; j < data[i].To; ++j) box = std::max(box, Box[j]);

		int left = std::min(data[i].Value, C - box);

		result += left;

		for (int j = data[i].From; j < data[i].To; ++j) Box[j] += left;
	}

	std::cout << result;
}