#include <iostream>
#include <algorithm>
#include <string>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 100 + 1;

std::string data[MAX][MAX];
int A, B;

std::string Add(std::string A, std::string B)
{
	int total = 0;
	std::string result;

	while (!A.empty() || !B.empty() || total)
	{
		if (!A.empty())
		{
			total += A.back() - '0';
			A.pop_back();
		}

		if (!B.empty())
		{
			total += B.back() - '0';
			B.pop_back();
		}

		result.push_back(total % 10 + '0');
		total /= 10;
	}

	std::reverse(result.begin(), result.end());

	return result;
}
std::string func(int A, int B)
{
	if (A == B || !B) return "1";

	auto& ret = data[A][B];
	if (ret != "") return ret;

	return ret = Add(func(A - 1, B - 1), func(A - 1, B));
}
int main()
{
	Init();

	std::cin >> A >> B;

	std::cout << func(A, B);
}