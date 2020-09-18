#include <iostream>

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 201;

int p[MAX];

bool result = true;
int N, M;

int find(int a)
{
	if (p[a] == -1) return a; // 부모가 없으면 자신을 리턴

	p[a] = find(p[a]); // 루트 노드가 모든 집합에 속한 노드의 부모가 되도록 한다
	return p[a];
}
void merge(int a, int b)
{
	p;
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[a] = b;
}
int main()
{
	Init();

	std::cin >> N >> M;

	for (int i = 1;i <= N; i++)
	{
		p[i] = -1;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int tmp;
			std::cin >> tmp;
			if (tmp)
			{
				merge(i, j);
			}
		}
	}

	int cur;
	int parent;
	for (int i = 0;i < M; i++)
	{
		std::cin >> cur;
		if (i == 0) parent = find(cur);
		else
		{
			if (parent != find(cur)) result = false;
		}
	}

	if (result) std::cout << "YES";
	else std::cout << "NO";
}
