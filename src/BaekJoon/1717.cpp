#include <iostream>
#include <vector>

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e6 + 1;

int N, M;

int p[MAX];
std::vector<bool> result;

int find(int a)
{
	if (p[a] == -1) return a;

	p[a] = find(p[a]);
	return p[a];
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[a] = b;
}

bool func(int a, int b) { return find(a) == find(b); }

int main()
{
	Init();

	std::cin >> N >> M;

	for (int i = 0; i <= N; i++)
	{
		p[i] = -1;
	}

	int cnt, a, b;
	for (int i = 0;i < M; i++)
	{
		std::cin >> cnt >> a >> b;
		if (cnt) result.push_back(func(a, b));
		else merge(a, b);
	}

	for (int i = 0;i < result.size(); i++)
	{
		if (result[i]) std::cout << "YES" << "\n";
		else std::cout << "NO" << "\n";
	}
}