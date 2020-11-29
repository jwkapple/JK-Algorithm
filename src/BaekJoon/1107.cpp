#include<iostream>
#include<string>
#include<stdlib.h>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

int INF = 1000007;
int broken[10];
int N, M;

int Min(int a, int b) {
	return a < b ? a : b;
}

bool possible(int k) {
	if (k == 0)
		return broken[0] ? false : true;
	while (k) {
		if (broken[k % 10] == 1) {
			return false;
		}
		k /= 10;
	}

	return true;
}

int find(int N) {
	int hundred = abs(N - 100);
	int buttonMin = INF;
	int temp;
	for (int i = 0; i <= INF; i++) {
		if (possible(i)) {
			temp = std::to_string(i).length();
			temp += abs(i - N);
			buttonMin = Min(buttonMin, temp);
		}
	}

	return Min(hundred, buttonMin);
}
int main()
{
	Init();

	std::cin >> N >> M;

	int tmp;
	for (int i = 0; i < M; i++)
	{
		std::cin >> tmp;
		broken[tmp] = 1;
	}

	std::cout << find(N) << std::endl;
}