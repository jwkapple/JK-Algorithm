#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e5 + 1;

int data[MAX];
int visited[MAX];
int G, P, result = 0;
int main()
{
	Init();

	std::cin >> G >> P;

	int cur;
	while (P--)
	{
		std::cin >> cur;

		if (!visited[cur]) visited[cur] = cur;
		int curP = visited[cur];
		while (data[curP])
		{
			curP--;
		}

		if (!curP) break;

		data[curP] = cur;
		visited[cur] = curP;
		result++;
	}

	std::cout << result;
}