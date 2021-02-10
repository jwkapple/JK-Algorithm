#include <iostream>
#include <vector>
#include <algorithm>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

struct Node
{
	int SM;
	int SD;
	int EM;
	int ED;

	Node(int x, int y, int X, int Y) : SM(x), SD(y), EM(X), ED(Y) {}
};

bool check(int cM, int cD, int M, int D) // true : latter is bigger
{
	if (cM < M) return true;
	else
	{
		if (cD < D) return true;
	}

	return false;
}
bool operator<(Node left, Node right)
{
	if (left.SM == right.SM)
	{
		return left.SD < right.SD;
	}
	else
	{
		return left.SM < right.SM;
	}
}

std::vector<Node> data;
int N, result = 0;

int main()
{
	Init();


	std::cin >> N;

	int a, b, c, d;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> a >> b >> c >> d;

		data.push_back(Node(a, b, c, d));
	}

	std::sort(data.begin(), data.end());

	int num = 0;
	int month = 3; int day = 1;
	int cM = 0, cD = 0;
	bool done = false;

	while (num < data.size())
	{
		auto[sM, sD, eM, eD] = data[num];

		if (!check(month, day, sM, sD)) // current point is latter
		{
			if (check(cM, cD, eM, eD)) // current date is sooner
			{
				cM = eM, cD = eD;
			}

			num++;
		}
		else
		{
			month = cM, day = cD;
			if (!month && !day) break;
			cM = 0, cD = 0;
			result++;
		}

		if (cM >= 12) { result++; done = true; break; }
	}

	if (done && cM == 12) std::cout << result;
	else std::cout << 0;
}
