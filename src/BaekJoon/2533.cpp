#include <iostream>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}
 
const int MAX = 1e6 + 2;

std::vector<int> child[MAX];
bool visited[MAX], EA[MAX];
int N, result = 0;

bool func(int cur)
{
	visited[cur] = true;
	auto size = child[cur].size();
	if (size == 1 && cur != 1) return false;

	auto& ret = EA[cur];
	ret = true;

	for (int i = 0; i < size; ++i)
	{
		if (visited[child[cur][i]]) continue;
		ret &= func(child[cur][i]);
	}

	if (!ret) { result++; ret = true; }
	else ret = false;
	return ret;
}

int main()
{	
	Init();
	
	std::cin >> N;	 
	
	int from, to;	
	for (int i = 0; i < N - 1; ++i)	 
	{		 
		std::cin >> from >> to;	

		child[from].push_back(to);
		child[to].push_back(from);
	}
	
	func(1);

	std::cout << result;
}