#include <iostream>
#include <vector>
#include <map>
#include <string>

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e5 + 1;
int T, N;
std::string A, B;

int num;
int p[MAX];
std::map<std::string, int> ID;
std::vector<int> result;

int find(int a)
{
	if (p[a] < 0) return a;

	p[a] = find(p[a]);
	return p[a];
}

int merge(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a == b) return p[a];

	if (p[a] > p[b])
	{
		p[b] += p[a];
		p[a] = b;

		return p[b];
	}
	else
	{
		p[a] += p[b];
		p[b] = a;

		return p[a];
	}
}

int findID(std::string name)
{
	auto tmp = ID.find(name);
	if (tmp == ID.end())
	{
		p[num] = -1;
		ID.insert(std::make_pair(name, num));
		return num++;
	}
	return tmp->second;
}

int main()
{
	Init();

	std::cin >> T;

	int a, b;
	while (T--)
	{
		std::cin >> N;

		ID.clear();
		num = 1;

		for (int i = 0;i < N; i++)
		{
			std::cin >> A >> B;
			a = findID(A);
			b = findID(B);
			result.push_back(merge(a, b));
		}
	}

	for (int i = 0;i < result.size(); i++)
	{
		std::cout << result[i] * -1 << "\n";
	}
}