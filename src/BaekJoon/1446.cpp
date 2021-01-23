#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define pii std::pair<int, int>

const int MAX = 13;

std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
int data[MAX][3];
int N, M;

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

int main() {

	Init();

	std::cin >> N >> M;

	for (int i = 0; i < N; ++i) { std::cin >> data[i][0] >> data[i][1] >> data[i][2]; }

	data[N][0] = M; data[N][1] = M;

	pq.push(pii(0, 0));

	while (!pq.empty())
	{
		auto [y, x] = pq.top(); pq.pop();
		if (x == M)
		{
			std::cout << y;
			break;
		}
		for (int i = 0; i <= N; ++i)
		{
			if (data[i][0] >= x) { pq.push(pii(data[i][2] + data[i][0] - x + y, data[i][1])); }
		}
	}
}