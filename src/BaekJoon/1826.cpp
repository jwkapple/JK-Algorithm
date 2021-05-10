#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

std::priority_queue<int> Q;
std::vector<pii> data;
int N, L, P, cur = 0;

int func(int num)
{
	if (num >= L) return 0;
	for (; cur < N; ++cur)
	{
		auto[l, v] = data[cur];

		if (l <= num) Q.push(v);
		else break;
	}

	if (Q.empty()) return -1;
	num += Q.top(); Q.pop();

	int result = func(num);
	if (result == -1) return -1;
	else return result + 1;
}
int main()
{
	Init();

	std::cin >> N;

	int a, b;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> a >> b;
		data.push_back(pii(a, b));
	}

	std::cin >> L >> P;

	std::sort(data.begin(), data.end());

	std::cout << func(P);
}