#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

std::unordered_map<std::string, int> origin;
std::vector<std::string> data;
int N, result = 0;

int main() {

	std::cin >> N;

	std::string tmp;
	for (int i = 0; i < N; i++)
	{
		std::cin >> tmp;
		origin.insert({ tmp, i });
	}

	for (int i = 0; i < N; i++)
	{
		std::cin >> tmp;
		data.push_back(tmp);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (origin[data[i]] > origin[data[j]])
			{
				result++;
				break;
			}
		}
	}
	std::cout << result;
}