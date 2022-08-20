#include <iostream>
#include <vector>
#include <queue>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 5e5 + 1;

std::vector<int> data[MAX];
int visited[MAX];
int N;

void func(int value, int level)
{
	visited[value] = level;

	ㄹ for (auto p : data[value])
	{
		if (!visited[p])
			func(p, level + 1);
	}
}

int main()
{
	Init();

	std::cin >> N;

	int A, B;
	for (int i = 1; i < N; ++i)
	{
		std::cin >> A >> B;

		data[A].push_back(B);
		data[B].push_back(A);
	}

	func(1, 0);

	int result = 0;
	for (int i = 1; i <= N; ++i)
	{
		result += visited[i];
	}

	if (result % 2)
		std::cout << "Yes";
	else
		std::cout << "No";
}