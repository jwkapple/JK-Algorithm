#include <iostream>
#include <vector>

std::vector<std::pair<int, int>> data;
std::vector<int> result;

int T, N, M;

int main()
{
	std::cin >> T;

	for (int a = 0; a < T; a++)
	{
		std::cin >> N >> M;
		std::pair<int, int> value;

		for (int i = 0; i < N; i++)
		{
			int tmp;
			std::cin >> tmp;

			if (i == M)
			{
				value.first = tmp;
				value.second = i;
			}

			data.push_back(std::make_pair(tmp, i));
		}


		int k = 0;
		int i = k;
		while (true)
		{
			if (i == data.size()) i = ++k;
			if (k == data.size()) break;
			int dest = data[k].first;
			if (data[i].first > dest)
			{
				data.push_back(data[k]);
				data.erase(data.begin() + k);
				i = k;
			}
			else i++;
		}

		for (int i = 0; i < data.size(); i++)
		{
			if (data[i].first == value.first && data[i].second == value.second)
			{
				result.push_back(i + 1);
				break;
			}
		}

		data.clear();
	}

	for (int i = 0; i < result.size(); i++)
	{
		std::cout << result[i] << "\n";
	}

}