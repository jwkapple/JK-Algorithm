#include <iostream>
#include <string>

#define ll long long

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 1e6 + 1;
const int ALPHA = 52 + 1;
const int DIV = 900528;

std::string data, ans;
int alpha[MAX], DP[MAX];
int L;
ll result = 0;

void func(int value)
{
	if (value == L - 1)
	{
		result += alpha[ans[value] - 'A' + 1];
		return;
	}

	int total = DP[L - value];

	total *= alpha[ans[value] - 'A' + 1] - 1;
	total %= DIV;

	result += total;

	func(value + 1);
}
int main()
{
	Init();

	std::cin >> data;
	std::cin >> ans;

	L = ans.length();
	for (int i = 0; i < data.size(); ++i)
	{
		alpha[data[i] - 'A' + 1] = i + 1;
	}

	result = 0;
	int tmp = data.length();
	int cur = 1, current = 1, prev = 1;
	while (cur != L)
	{
		current = (prev * tmp) % DIV;
		result += current;
		result %= DIV;
		prev = current;
		DP[cur++] = current;
	}

	func(0);
	std::cout << result;
}