#include <iostream>
#include <vector>
#include <string>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

std::vector<int> colon;
std::string data;

int main()
{
	Init();

	std::cin >> data;

	colon.push_back(-1);
	for (int i = 0; i < data.size(); ++i)
	{
		if (data[i] == ':')
			colon.push_back(i);
	}

	colon.push_back(data.size());

	int interval;
	for (int i = 0; i < colon.size() - 1; ++i)
	{
		interval = colon[i + 1] - colon[i];

		if (interval == 1)
		{
			if (i == 0)
			{
				std::cout << "0000:";
			}
			else if (i == colon.size() - 2)
			{
				std::cout << "0000";
			}
			else
			{
				int value = 10 - colon.size();
				for (int j = 0; j < value; ++j)
				{
					std::cout << "0000:";
				}
			}
		}
		else
		{
			int tmp = 5 - interval;
			for (int j = 0; j < tmp; ++j)
			{
				std::cout << "0";
			}

			for (int j = colon[i] + 1; j < colon[i + 1]; ++j)
			{
				std::cout << data[j];
			}

			if (i != colon.size() - 2)
				std::cout << ":";
		}
	}
}