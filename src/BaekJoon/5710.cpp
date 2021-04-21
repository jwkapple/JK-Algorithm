#include <iostream>
#include <algorithm>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 990000;
int M, N, A, B;
int func(int A) {
	int total = 0;
	total += std::min(A, 200) / 2;
	A -= 200;
	if (A > 0) {
		total += std::min(A, 29700) / 3;
		A -= 29700;
		if (A > 0) {
			total += std::min(A, 4950000) / 5;
			A -= MAX * 5;
			if (A > 0) {
				total += A / 7;
			}
		}
	}
	return total;
}
int calc(int A)
{
	int total = 0;
	total += std::min(A, 100) * 2;
	A -= 100;
	if (A > 0)
	{
		total += std::min(A, 9900) * 3;
		A -= 9900;
		if (A > 0) {
			total += std::min(A, MAX) * 5;
			A -= MAX;
			if (A > 0) {
				total += A * 7;
			}
		}
	}
	return total;
}
int main() {

	Init();

	std::cin >> A >> B;

	while (true)
	{
		if (!A && !B) break;

		int sum = func(A);
		int lo = 0, hi = sum;
		while (lo <= hi)
		{
			int mid = (lo + hi) / 2;
			M = mid; N = sum - M;

			int left = calc(M); int right = calc(N);

			if (right - left == B)
			{
				std::cout << left << "\n";
				break;
			}
			if (right - left > B) lo = mid + 1;
			else hi = mid - 1;

		}
	}
}