#include <iostream>
#include <vector>
#include <string>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 100 + 1;

bool visited[MAX];
std::vector<int> result;
std::string data;
int L, R;

void func(int L, int R)
{
	if (L == R)
	{
		result.push_back(L);
		return;
	}

	if (L + 1 == R)
	{
		bool LR = data[L] > data[R];
		result.push_back(LR ? R : L);
		result.push_back(LR ? L : R);
		return;
	}

	int min = 1e9, minNum;

	for (int i = L; i <= R; ++i)
	{
		if (data[i] < min)
		{
			min = data[i];
			minNum = i;
		}
	}

	result.push_back(minNum);

	func(minNum + 1, R);
	func(L, minNum - 1);
}

int main()
{
	Init();

	std::cin >> data;

	L = 0, R = data.size() - 1;

	func(L, R);

	for (int i = 0; i < data.size(); ++i)
	{
		visited[result[i]] = true;
		for (int j = 0; j < data.size(); ++j)
		{
			if (visited[j])
				std::cout << data[j];
		}

		std::cout << "\n";
	}
}