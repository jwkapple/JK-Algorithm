#include <iostream>
#include <algorithm>
#include <climits>

#define ll long long

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 5000 + 1;
long long data[MAX];
int N;
ll min = LLONG_MAX, L, M, R;

int main()
{
	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> data[i];
	}

	std::sort(data, data + N);

	ll x;

	int tmp;
	for (int i = 0; i < N - 2; ++i)
	{
		tmp = data[i];
		int left = i + 1;
		int right = N - 1;
		while (left < right)
		{
			ll value = tmp + data[left] + data[right];
			if (min > std::abs(value)) {
				min = std::abs(value);
				L = tmp;
				M = data[left];
				R = data[right];
			}
			if (value < 0) left++;
			else if (value > 0) right--;
			else { i = N; break; }
		}
	}

	std::cout << L << " " << M << " " << R << "\n";
}