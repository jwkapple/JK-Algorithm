#include <iostream>
#include <string>
#include <map>

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

std::map <std::string, int> data;

int main()
{
	Init();

	data.insert(std::make_pair("black", 0));
	data.insert(std::make_pair("brown", 1));
	data.insert(std::make_pair("red", 2));
	data.insert(std::make_pair("orange", 3));
	data.insert(std::make_pair("yellow", 4));
	data.insert(std::make_pair("green", 5));
	data.insert(std::make_pair("blue", 6));
	data.insert(std::make_pair("violet", 7));
	data.insert(std::make_pair("grey", 8));
	data.insert(std::make_pair("white", 9));

	std::string first, second, third;

	std::cin >> first >> second >> third;

	if (first != "black")std::cout << data.find(first)->second;
	std::cout << data.find(second)->second;

	if (first == "black" && second == "black");
	else
	{
		for (int i = 0; i < data.find(third)->second; i++)
		{
			std::cout << 0;
		}
	}
}