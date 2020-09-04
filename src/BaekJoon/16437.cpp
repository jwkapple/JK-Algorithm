#include <iostream>
#include <vector>

struct Node
{
	char animal;
	unsigned long size;

	Node() = default;
	Node(char A, unsigned long S) : animal(A), size(S) {}
};
class Tree
{
public:
	std::vector<int> parents;
	std::vector<std::vector<int>> children;
	std::vector<Node> data;
	int N;

	Tree() : N(0) {}
	Tree(int n) : N(n)
	{
		parents.resize(N + 1, -1);
		children.resize(N + 1);
		data.resize(N + 1);
		data[1].animal = 'W';
		data[1].size = 0;
	}

	void add(char animal, unsigned long num, int parent, int child)
	{
		Node node(animal, num);

		parents[child] = parent;
		children[parent].push_back(child);
		data[child] = node;
	}

	void back(int root)
	{
		for (int i = 0;i < children[root].size(); i++)
		{
			back(children[root][i]);
		}

		if (root != 1) escape(root);
	}

	void print()
	{

		for (int i = 1;i <= N; i++)
		{
			std::cout << "Node " << i << ": Parent (" << parents[i] << "), ";
			std::cout << "Animal : " << data[i].animal << "||" << data[i].size << ", ";
			std::cout << "children (";

			for (int j = 0; j < children[i].size(); j++)
			{
				std::cout << children[i][j];
				if (j != children[i].size()) std::cout << ", ";
			}

			std::cout << ")" << "\n";
		}
	}

	void escape(int root)
	{
		if (data[root].animal == 'S')
		{

			switch (data[parents[root]].animal)
			{
			case 'S': data[parents[root]].size += data[root].size; break;

			case 'W':
				if (data[parents[root]].size > data[root].size) data[parents[root]].size -= data[root].size;
				else
				{
					data[parents[root]].size = data[root].size - data[parents[root]].size;
					data[parents[root]].animal = 'S';
				}
				break;
			}
		}
	}
};

int main()
{
	int N;
	std::cin >> N;

	Tree T(N);

	char animal;
	int parent;
	unsigned long num;
	for (int i = 1; i < N; i++)
	{
		std::cin >> animal >> num >> parent;

		T.add(animal, num, parent, i + 1);
	}
	T.back(1);

	std::cout << T.data[1].size;
}