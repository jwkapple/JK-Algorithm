#include <iostream>
#include <algorithm>

#ifdef TEST
#include <fstream>
std::ifstream readFile;

char c;
inline int toInt() { return static_cast<int>(c) - '0'; }
#endif // TEST

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

typedef std::pair<int, int> pii;

int N, K, minA[500001];
long long sum;
pii p[500001];

int main() {

	Init();

	std::cin >> N;
	for (int i = 0; i < N; i++) std::cin >> p[i].first >> p[i].second;

	std::sort(p, p + N, [](const pii& i, const pii& j) { return i.second < j.second; });

	minA[N] = 2e9;
	for (int i = N - 1; i >= 0; i--) minA[i] = std::min(p[i].first, minA[i + 1]);
	for (int i = 0; i < N; i++)
	{
		if (p[K].second - p[K].first < p[i].second - p[i].first) K = i;
		sum += (long long)p[i].second;
		std::cout << std::min(sum - p[K].second + p[K].first, sum - p[i].second + minA[i]) << "\n";
	}
}