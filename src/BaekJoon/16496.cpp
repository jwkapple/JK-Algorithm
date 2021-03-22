#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1000 + 1;
std::vector<std::string> data[10];
int N;

int main()
{
	Init();

	std::cin >> N;

	bool isZero = true;
	std::string tmp;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> tmp;
		if (tmp != "0") isZero = false;
		data[tmp[0] - '0'].push_back(tmp);
	}

	for (int i = 1; i < 10; ++i)
	{
		int s = data[i].size();
		if (s == 0 || s == 1) continue;

		std::sort(data[i].begin(), data[i].end(), [](std::string A, std::string B)
		{
			std::string L = A + B;
			std::string R = B + A;

			int size = L.size();
			int cur = 0;
			while (cur != size)
			{
				if (L[cur] == R[cur]) cur++;
				else
				{
					return L[cur] > R[cur];
				}
			}

			return L[cur] > R[cur];
		});
	}

	if (isZero) std::cout << 0;
	else
	{
		for (int i = 9; i >= 0; --i)
		{
			for (auto p : data[i])
			{
				std::cout << p;
			}
		}
	}
}