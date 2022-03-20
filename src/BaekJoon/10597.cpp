#include <iostream>
#include <string>
#include <stack>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 100 + 1;

std::stack<int> result;
bool visited[MAX];
std::string data;
int size, nSize = 0, max = 0;

bool func(int num)
{
	if (num == size)
	{
		return nSize == max;
	}

	int curMax = max;
	nSize++;
	int cur = (int)(data[num] - '0');

	if (!cur)
	{
		nSize--;
		return false;
	}

	if (!visited[cur])
	{
		visited[cur] = true;

		max = cur > max ? cur : max;

		if (func(num + 1))
		{
			result.push(cur);
			return true;
		}
		else
		{
			max = curMax;
			visited[cur] = false;
		}
	}

	if (num + 1 == size)
	{
		nSize--;
		return false;
	}

	cur = cur * 10 + (int)(data[num + 1] - '0');
	if (cur <= 50 && !visited[cur])
	{
		visited[cur] = true;

		max = cur > max ? cur : max;

		if (func(num + 2))
		{
			result.push(cur);
			return true;
		}
		else
		{
			max = curMax;
			visited[cur] = false;
		}
	}

	nSize--;
	return false;
}

int main()
{
	Init();

	std::cin >> data;

	size = data.size();
	func(0);

	while (!result.empty())
	{
		std::cout << result.top() << " ";
		result.pop();
	}
}