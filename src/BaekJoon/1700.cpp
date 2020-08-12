#include <iostream>
#include <queue>
const int MAX = 101;

std::queue<int> data[MAX];   // 각 전자기기의 사용	
int turn[MAX];
int plug[MAX];
bool isPlugged[MAX]{ false };
int N, K;
int size = 0, result = 0;

void func()
{
	for (int i = 0; i < K; i++)
	{
		if (size != N)
		{
			if (isPlugged[turn[i]] == true)
			{
				data[turn[i]].pop();
			}
			else
			{
				plug[size] = turn[i];
				data[turn[i]].pop();
				isPlugged[turn[i]] = true;
				size++;
			}
		}

		else
		{
			if (isPlugged[turn[i]] == true)
			{
				data[turn[i]].pop();
			}
			else
			{
				int max = -1;
				int currentMax;
				for (int j = 0; j < size; j++)
				{
					if (data[plug[j]].empty() == true)
					{
						currentMax = j;
						break;
					}
					else
					{
						if (data[plug[j]].front() > max)
						{
							currentMax = j;
							max = data[plug[j]].front();
						}
					}
				}

				isPlugged[plug[currentMax]] = false;
				plug[currentMax] = turn[i];
				isPlugged[turn[i]] = true;
				data[turn[i]].pop();
				result++;
			}
		}
	}
}
int main()
{
	std::cin >> N >> K;

	for (int i = 0; i < K; i++)
	{
		int tmp;

		std::cin >> tmp;

		turn[i] = tmp;

		data[tmp].push(i);
	}

	func();

	std::cout << result;
}