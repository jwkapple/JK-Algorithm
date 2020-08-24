#include <iostream>
#include <vector>
#include <algorithm>

const int MAX = 15;

char data[MAX];
std::vector<char> table;

int vowel = 0;
int consonent = 0;

int L, C;

bool check(char alpha)
{
	if (alpha == 'a' || alpha == 'i' || alpha == 'o' || alpha == 'u' || alpha == 'e') return true;

	return false;
}

void print()
{
	for (int i = 0;i < table.size(); i++)
	{
		std::cout << table[i];
	}

	std::cout << "\n";
}
void back(int index, int num) // 벡터순서, 들어간 수
{
	if (index > C) return;
	if (num == L)
	{
		if (vowel >= 1 && consonent >= 2) print();
		return;
	}

	table.push_back(data[index]);
	bool vow = check(data[index]);

	if (vow) vowel++;
	else consonent++;

	back(index + 1, ++num);

	table.pop_back();

	if (vow) vowel--;
	else consonent--;

	back(index + 1, --num);
}

int main()
{
	std::cin >> L >> C;

	for (int i = 0;i < C; i++)
	{
		std::cin >> data[i];
	}

	std::sort(data, data + C);

	back(0, 0);
}