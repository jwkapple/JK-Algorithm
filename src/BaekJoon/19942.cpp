#include <iostream>
#include <algorithm>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

struct Node
{
	int P;
	int F;
	int S;
	int V;
	int C;

	Node() {};
	Node(int p, int f, int s, int v, int c) : P(p), F(f), S(s), V(v), C(c) {};
};

const int INF = 1e9;
const int MAX = 15 + 1;

Node data[MAX];
int N, mp, mf, ms, mv;

pii func(int num, int current, int c, int nv, int np, int nf, int ns)
{
	if (np >= mp && nf >= mf && ns >= ms && nv >= mv)
	{
		return pii(current, c);
	}

	if (num == N + 1) return pii(current, INF);

	auto[p, f, s, v, C] = data[num];

	pii off = func(num + 1, current, c, nv, np, nf, ns);
	auto[offC, offV] = off;

	np += p;
	nf += f;
	ns += s;
	nv += v;

	pii on = func(num + 1, current | 1 << num, c + C, nv, np, nf, ns);
	auto[onC, onV] = on;

	if (offV == onV)
	{
		for (int i = 1; i < MAX; ++i)
		{
			if ((onC & 1 << i) && !(offC & 1 << i)) return on;
			if ((offC & 1 << i) && !(onC & 1 << i)) return off;
		}
	}

	return offV > onV ? on : off;
}

int main()
{
	Init();

	std::cin >> N;

	std::cin >> mp >> mf >> ms >> mv;

	int v, p, f, s, c;
	for (int i = 1; i <= N; ++i)
	{
		std::cin >> p >> f >> s >> v >> c;

		data[i] = Node(p, f, s, v, c);
	}

	pii result = func(1, 0, 0, 0, 0, 0, 0);
	auto[C, V] = result;
	if (V == INF) std::cout << -1 << "\n";
	else
	{
		std::cout << V << "\n";

		for (int i = 1; i <= N; ++i)
		{
			if (C & 1 << i) std::cout << i << " ";
		}
	}
}