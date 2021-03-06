#include<iostream>
#include<algorithm>

#define ll long long

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

int MAX = 100 + 1;
int N;
ll data[MAX];

int main(int argc, char* argv[]) {

	Init();

	std::cin >> N;

	for (int i = 0; i <= 5; ++i) { data[i] = i; }

	for (int i = 6; i <= N; i++) {
		data[i] = std::max({ data[i - 1] + 1, data[i - 3] * 2, data[i - 4] * 3, data[i - 5] * 4 });
	}

	std::cout << data[N] << "\n";
}