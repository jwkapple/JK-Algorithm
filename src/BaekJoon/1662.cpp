#include <iostream>
#include <string>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

std::string data;
int size;

pii func(int num)
{
	int ret = 0, tmp;
	while (num != size)
	{
		switch (data[num])
		{
		case '(':
		{
			pii value = func(num + 1);

			ret += ((data[num - 1] - '0') * value.first) - 1;
			num = value.second + 1;
			break;
		}

		case ')':
			return pii(ret, num);
		default:
		{
			ret++;
			num++;
			break;
		}
		}
	}

	return pii(ret, num);
}
int main()
{
	Init();

	std::cin >> data;

	data.append(")");
	size = data.size();

	pii value = func(0);
	std::cout << value.first;
}