#include <iostream>
#include <map>
#include <string>

const int MAX = 1e5 + 1;

std::map<std::string, int> name;
std::map<int, std::string> num;
std::string result[MAX];
int N, M;

int main()
{
	std::cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		std::string pokemon;
		std::cin >> pokemon;
		name.emplace(pokemon, i);
		num.emplace(i, pokemon);
	}

	for (int i = 0; i < M; i++)
	{
		std::string instruct;
		std::cin >> instruct;

		if (static_cast<int>(instruct[0]) >= '0' && static_cast<int>(instruct[0]) <= '9')
		{
			result[i] = num[std::stoi(instruct)];
		}
		else
		{
			result[i] = std::to_string(name[instruct]);
		}
	}

	for (int i = 0; i < M; i++)
	{
		if (static_cast<int>(result[i][0]) >= '0' && static_cast<int>(result[i][0]) <= '9')
		{
			std::cout << std::stoi(result[i]) << "\n";
		}
		else
		{
			std::cout << result[i] << "\n";
		}
	}
}