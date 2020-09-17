#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

int length, width, height;
int N;
std::vector<std::pair<int, int>> box;
bool impossible;
int result = 0;

void func(int l, int w, int h)
{
	if (impossible) return;
	if (l == 0 || w == 0 || h == 0) return;
	for (int i = 0; i < N; i++)
	{
		int cur = box[i].first;
		if (l >= cur && w >= cur && h >= cur && box[i].second > 0)
		{
			box[i].second--;
			result++;
			func(l, w - cur, cur);
			func(l - cur, cur, cur);
			func(l, w, h - cur);
			if (!impossible) return;
		}
	}

	impossible = true;
	result = -1;

	return;
}
int main()
{
	Init();

	std::cin >> length >> width >> height;
	std::cin >> N;
	box.resize(N);

	int var, size;

	for (int i = 0;i < N; i++)
	{
		std::cin >> var >> size;
		var = std::pow(2, var);
		box[i] = std::make_pair(var, size);
	}

	std::sort(box.begin(), box.end(), [](std::pair<int, int>& left, std::pair<int, int>& right)
	{
		return left.first > right.first;
	});

	func(length, width, height);

	std::cout << result;
}