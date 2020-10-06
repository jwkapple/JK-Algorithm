#include <iostream>
#include <climits>
#include <algorithm>

#ifdef TEST
#include <fstream>
std::ifstream readFile;
#endif // TEST

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e5 + 1;

int data[MAX];
int count = 0;

int N;

int func(int from, int to, int num, const int* data)
{
	if (from == to) return from;
	if (from + 1 == to)
	{
		if (data[from] > num) return from;
		else return to;
	}

	int middle = (from + to) / 2;
	if (data[middle] > num) return func(from, middle, num, data);
	else return func(middle + 1, to, num, data);
}

void LIS(int num, int* data, int& count)
{
	if (data[count] < num)
	{
		data[++count] = num;
		return;
	}

	data[func(0, count, num, data)] = num;
}

int main()
{
	Init();

	std::cin >> N;

	data[0] = INT_MIN;
	std::fill(data + 1, data + N + 1, INT_MAX);

	int tmp;
	for (int i = 1;i <= N; i++)
	{
		std::cin >> tmp;
		LIS(tmp, data, count);
	}

	std::cout << count;
}