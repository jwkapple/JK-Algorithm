#include <iostream>
#include <vector>

#ifdef TEST
#include <fstream>
std::ifstream readFile;
#endif // TEST

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 9;
int square[3][3]; //  박스 check
int horizontal[MAX]; // 가로 check
int vertical[MAX]; // 세로 check

std::vector<std::pair<int, int>> data;

int board[MAX][MAX];

bool Horizontal(int line, int num) { return !(horizontal[line] & (1 << num)); }
bool Vertical(int line, int num) { return !(vertical[line] & (1 << num)); }
bool Square(int y, int x, int num) { return !(square[y][x] & (1 << num)); }

void Add(int y, int x, int num)
{
	if (num > 0)
	{
		horizontal[y] |= (1 << num);
		vertical[x] |= (1 << num);
		square[y / 3][x / 3] |= (1 << num);
		board[y][x] = num;
	}
	else
	{
		horizontal[y] &= ~(1 << -1 * num);
		vertical[x] &= ~(1 << -1 * num);
		square[y / 3][x / 3] &= ~(1 << -1 * num);
		board[y][x] = 0;
	}
}

bool func(int size)
{
	if (size == data.size()) return true;

	std::pair<int, int> current = data[size];

	for (int i = 1; i <= MAX; i++)
	{
		if (Horizontal(current.first, i) && Vertical(current.second, i) && Square(current.first / 3, current.second / 3, i))
		{
			Add(current.first, current.second, i);
			if (func(size + 1)) return true;
			Add(current.first, current.second, -i);
		}
	}

	return false;
}
int main()
{
	Init();

#ifdef TEST
	readFile.open("testCase.txt");
#endif // TEST

	int tmp;
	for (int y = 0; y < MAX; y++)
	{
		for (int x = 0; x < MAX; x++)
		{
#ifdef TEST
			char c;
			readFile.get(c);
			tmp = static_cast<int>(c) - 48;
			readFile.get(c);
#endif // TEST
#ifndef TEST
			std::cin >> tmp;
#endif // !1

			if (tmp)
			{
				Add(y, x, tmp);
			}
			else data.push_back(std::make_pair(y, x));
		}
	}

	func(0);

	for (int y = 0; y < MAX; y++)
	{
		for (int x = 0; x < MAX; x++)
		{
			std::cout << board[y][x];
			if (x != MAX - 1) std::cout << " ";
		}

		if (y != MAX - 1) std::cout << "\n";
	}
}
