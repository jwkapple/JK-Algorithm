#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e6 + 1;

bool visited[MAX];
int data[MAX];
int N, current = 0;

int find(int from, int to, int num)
{
	if (from == to) return from;
	if (from + 1 == to)
	{
		if (data[from] > num) return from;
		else return to;
	}

	int mid = (from + to) / 2;

	if (data[mid] > num) return find(from, mid, num);
	else return find(mid + 1, to, num);
}

int main()
{
	Init();

	std::cin >> N;

	data[0] = -1 * 1e9;
	int tmp;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> tmp;

		if (!visited[tmp])
		{
			if (tmp > data[current]) data[++current] = tmp;
			else
			{
				int v = find(0, current, tmp);
				visited[data[v]] = false;
				data[v] = tmp;
			}

			visited[tmp] = true;
		}

	}

	std::cout << current;
}
