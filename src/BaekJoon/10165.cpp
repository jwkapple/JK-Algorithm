#include <iostream>
#include <algorithm>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

struct Node
{
	int From;
	int To;
	int Num;

	Node() {};
	Node(int f, int t, int n) : From(f), To(t), Num(n) {};
};

const int MAX = 5e5 + 1;

bool visited[MAX];
std::vector<Node> normal, over;

int N, M;
int main()
{
	Init();

	std::cin >> N >> M;

	int a, b;
	for (int i = 1; i <= M; ++i)
	{
		std::cin >> a >> b;
		if (a > b)
		{
			if (!b) normal.push_back(Node(a, 1e9, i));
			else over.push_back(Node(a, b, i));
		}
		else normal.push_back(Node(a, b, i));

	}

	std::sort(over.begin(), over.end(), [](Node L, Node R)
	{
		if (L.From == R.From)
		{
			return L.To > R.To;
		}
		return L.From < R.From;
	});

	std::sort(normal.begin(), normal.end(), [](Node L, Node R)
	{
		if (L.From == R.From)
		{
			return L.To > R.To;
		}
		return L.From < R.From;
	});

	// Over
	for (int i = 0; i < over.size(); ++i)
	{
		if (visited[over[i].Num]) continue;
		auto[F, T, N] = over[i];

		// over
		for (int j = i + 1; j < over.size(); ++j)
		{
			if (visited[over[j].Num]) continue;

			auto[cF, cT, cN] = over[j];
			if (cT <= T) visited[cN] = true;
		}

		// normal
		for (int k = 0; k < normal.size(); ++k)
		{
			if (visited[normal[k].Num]) continue;

			auto[cF, cT, cN] = normal[k];
			if (cF <= T && cT <= T) visited[cN] = true;
			if (F <= cF && F <= cT) visited[cN] = true;
		}
	}

	// Normal
	for (int i = 0; i < normal.size(); ++i)
	{
		if (visited[normal[i].Num]) continue;
		auto[F, T, N] = normal[i];

		for (int j = i + 1; j < normal.size(); ++j)
		{
			if (visited[normal[j].Num]) continue;

			auto[cF, cT, cN] = normal[j];
			if (T <= cF) break;
			if (cT <= T) visited[cN] = true;
		}
	}

	for (int i = 1; i <= M; ++i)
	{
		if (!visited[i]) std::cout << i << " ";
	}
}