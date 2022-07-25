#include <iostream>
#include <string>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void printRome(int &value, std::string character, int charValue)
{
	int total = value / charValue;

	for (int i = 0; i < total; ++i)
	{
		std::cout << character;
	}

	value -= total * charValue;
}

void Rome(int value)
{
	printRome(value, "M", 1000);
	printRome(value, "CM", 900);
	printRome(value, "D", 500);
	printRome(value, "CD", 400);
	printRome(value, "C", 100);
	printRome(value, "XC", 90);
	printRome(value, "L", 50);
	printRome(value, "XL", 40);
	printRome(value, "X", 10);
	printRome(value, "IX", 9);
	printRome(value, "V", 5);
	printRome(value, "IV", 4);
	printRome(value, "I", 1);
}

int func()
{
	int total = 0;

	std::string data;

	std::cin >> data;

	int length = data.length();

	for (int i = length - 1; i >= 0; --i)
	{
		switch (data[i])
		{
		case 'I':
		{
			total += 1;
			break;
		}

		case 'V':
		{
			if (i > 0)
			{
				if (data[i - 1] == 'I')
				{
					total += 4;
					i--;
					break;
				}
			}

			total += 5;
			break;
		}
		case 'X':
		{
			if (i > 0)
			{
				if (data[i - 1] == 'I')
				{
					total += 9;
					i--;
					break;
				}
			}

			total += 10;
			break;
		}

		case 'L':
		{
			if (i > 0)
			{
				if (data[i - 1] == 'X')
				{
					total += 40;
					i--;
					break;
				}
			}

			total += 50;
			break;
		}

		case 'C':
		{
			if (i > 0)
			{
				if (data[i - 1] == 'X')
				{
					total += 90;
					i--;
					break;
				}
			}

			total += 100;
			break;
		}

		case 'D':
		{
			if (i > 0)
			{
				if (data[i - 1] == 'C')
				{
					total += 400;
					i--;
					break;
				}
			}

			total += 500;
			break;
		}

		case 'M':
		{
			if (i > 0)
			{
				if (data[i - 1] == 'C')
				{
					total += 900;
					i--;
					break;
				}
			}

			total += 1000;
			break;
		}
		}
	}

	return total;
}

int main()
{
	Init();

	int tA = func();
	int tB = func();

	int total = tA + tB;

	std::cout << total << "\n";
	Rome(total);
}