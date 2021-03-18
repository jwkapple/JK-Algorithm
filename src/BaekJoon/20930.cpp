#include <iostream>
#include <algorithm>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

void Union(int A, int B);
bool Find(int A, int B);

struct Node
{
	int From;
	int To;
	int Num;

	Node(int f, int t, int n) : From(f), To(t), Num(n) {}
};

const int MAX = 2e5 + 5;

std::vector<Node> Height, Width;
std::vector<int> result;
int parent[MAX];
int N, M, num = 0;

int GetParent(int A)
{
	if (parent[A] == A) return A;
	else return parent[A] = GetParent(parent[A]);
}

void Union(int A, int B)
{
	A = GetParent(A);
	B = GetParent(B);

	if (A > B) parent[A] = B;
	else parent[B] = A;
}

bool Find(int A, int B)
{
	A = GetParent(A);
	B = GetParent(B);

	return A == B;
}

void Input(int x, int y, int xP, int yP, int i)
{
	if (x > xP) Width.push_back(Node(xP, x, i));
	else Width.push_back(Node(x, xP, i));

	if (y > yP) Height.push_back(Node(yP, y, i));
	else Height.push_back(Node(y, yP, i));
}

int main()
{
	Init();

	std::cin >> N >> M;

	int x, y, xP, yP;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> x >> y >> xP >> yP;

		Input(x, y, xP, yP, i);
		parent[i] = i;
	}

	std::sort(Height.begin(), Height.end(), [](Node L, Node R) { return L.From < R.From;});
	std::sort(Width.begin(), Width.end(), [](Node L, Node R) { return L.From < R.From;});

	int cur = 0;
	while (cur < N)
	{
		auto[from, to, num] = Width[cur];

		while (to >= Width[cur].From && cur < N)
		{
			to = to > Width[cur].To ? to : Width[cur].To;
			if (!Find(num, Width[cur].Num)) Union(num, Width[cur].Num);
			cur++;
			if (cur == N) break;
		}
	}

	cur = 0;

	while (cur < N)
	{
		auto[from, to, num] = Height[cur];

		while (to >= Height[cur].From && cur < N)
		{
			to = to > Height[cur].To ? to : Height[cur].To;
			if (!Find(num, Height[cur].Num)) Union(num, Height[cur].Num);
			cur++;
			if (cur == N) break;
		}
	}

	int A, B;

	for (int i = 0; i < M; ++i)
	{
		std::cin >> A >> B;

		result.push_back(Find(A - 1, B - 1));
	}

	for (auto p : result)
	{
		std::cout << p << "\n";
	}
}