#include <iostream>
#include <vector>

class Tree
{
public:
	std::vector<char> parents;
	std::vector<std::vector<char>> children;
	int N;

	Tree() : N(0) {}
	Tree(int n) : N(n)
	{
		parents.resize(N, -1);
		children.resize(N);
	}

	void add(int from, int to)
	{
		children[from].push_back(to);
	}

	void front(int cur)
	{
		if (cur == -1) return;
		std::cout << static_cast<char>(cur + 'A');

		for (int i = 0; i < children[cur].size(); i++)
		{
			front(children[cur][i]);
		}
	}

	void middle(int cur)
	{
		if (cur == -1) return;

		middle(children[cur][0]);
		std::cout << static_cast<char>(cur + 'A');
		middle(children[cur][1]);
	}
	void back(int cur)
	{
		if (cur == -1) return;

		for (int i = 0; i < children[cur].size(); i++)
		{
			back(children[cur][i]);
		}

		std::cout << static_cast<char>(cur + 'A');
	}
};
int main()
{
	int tmp;
	std::cin >> tmp;

	Tree T(26);

	for (int i = 0; i < tmp; i++)
	{
		char parent, children;

		std::cin >> parent;

		for (int j = 0; j < 2; j++)
		{
			std::cin >> children;
			if (children != '.') T.add(parent - 'A', children - 'A');
			else T.add(parent - 'A', -1);
		}
	}

	T.front(0);
	std::cout << "\n";
	T.middle(0);
	std::cout << "\n";
	T.back(0);
}