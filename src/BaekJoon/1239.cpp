#include <iostream>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

const int MAX = 8 + 1;

bool visited[MAX];
int data[MAX], value[MAX];
int N, result = 0;

void calc()
{
	int resultT = 0;
	int total = 0, sLine = 0;
	for (int i = 0; i < N; ++i)
	{
		resultT += value[i];

		if (resultT > 50)
			break;

		for (int j = i; j < N; ++j)
		{
			total += value[j];
			if (total == 50)
				sLine++;

			if (total >= 50)
				break;
		}

		total = 0;
	}

	result = result < sLine ? sLine : result;
}
void func(int cur)
{
	if (cur == N)
	{
		calc();
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		if (!visited[i])
		{
			visited[i] = true;
			value[cur] = data[i];
			func(cur + 1);
			visited[i] = false;
		}
	}
}
int main()
{
	Init();

	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> data[i];
	}

	func(0);

	std::cout << result;
}