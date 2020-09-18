#include <iostream>

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e4 + 1;

int N, M, k;
short int p[MAX];
short int pay[MAX];

short int find(short int a)
{
	if (p[a] < 0) return a;
	p[a] = find(p[a]);

	return p[a];
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a == b) return;

	if (pay[a] > pay[b])
	{
		p[b] += p[a];
		p[a] = b;
		pay[a] = 0;
	}
	else
	{
		p[a] += p[b];
		p[b] = a;
		pay[b] = 0;
	}
}
int main()
{
	Init();

	std::cin >> N >> M >> k;

	for (int i = 1; i <= N; i++)
	{
		p[i] = -1;
		std::cin >> pay[i];
	}

	int a, b;
	for (int i = 0;i < M; i++)
	{
		std::cin >> a >> b;
		merge(a, b);
	}

	int total = 0;
	int totalCost = 0;

	for (int i = 1; i <= N; i++)
	{
		if (p[i] < 0)
		{
			total += p[i];
			totalCost += pay[i];
		}
	}

	total *= -1;

	if (total != N) std::cout << "Oh no";
	else
	{
		if (totalCost > k) std::cout << "Oh no";
		else std::cout << totalCost;
	}
}
