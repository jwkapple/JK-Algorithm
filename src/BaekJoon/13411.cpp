#include <iostream>
#include <algorithm>
#include <cmath>

const int MAX = 1e5 + 1;

std::pair<double, int> result[MAX]; // <Time, Robot>
int N;

double getDist(double x, double y)
{
	return std::sqrt(x * x + y * y);
}

int main()
{
	std::cin >> N;

	for (int i = 0;i < N; i++)
	{
		double x, y, v;

		std::cin >> x >> y >> v;

		result[i].first = getDist(x, y) / v;
		result[i].second = i+1;
	}

	std::sort(result, result + N);

	for (int i = 0;i < N; i++)
	{
		std::cout << result[i].second << "\n";
	}
}
