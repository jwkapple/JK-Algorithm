#include <iostream>
#include <string>
#include <algorithm>

#ifdef TEST
#include <fstream>
std::ifstream readFile;
#endif // TEST

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 10;

int data[MAX][MAX];
int chain[MAX][MAX];

int fill(int y, int x)
{
	if (x == MAX)
	{
		return 1;
	}

	if (data[y][x + 1])
	{
		chain[y][x] = fill(y, x + 1) + 1;
		return chain[y][x];
	}
	else
	{
		chain[y][x] = 1;
		return chain[y][x];
	}
}
int main()
{
	Init();
#ifdef TEST
	readFile.open("testCase.txt");
	char c;
	if (readFile.is_open())    //파일이 열렸는지 확
	{
		for (int y = 0; y < MAX; y++)
		{
			for (int x = 0; x < MAX; x++)
			{
				readFile.get(c);
				readFile.get();
				data[y][x] = static_cast<int>(c) - '0';
			}
		}
	}

	readFile.close();
#endif // TEST

#ifndef TEST
	std::cin >> data;
#endif // !TEST

	/*
	for (int y = 0; y < MAX; y++)
	{
	   for (int x = 0; x < MAX; x++)
	   {
		  std::cout << data[y][x] << " ";
	   }
	   if (y != MAX - 1) std::cout << "\n";
	}
	*/

	std::fill(chain, chain + sizeof(chain), -1);

	for (int i = 0; i < MAX; i++)
	{
		fill(i, 0);
	}


}