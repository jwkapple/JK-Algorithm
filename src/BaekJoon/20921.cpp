#include <iostream>
#include <vector>
void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 4243;

std::vector<int> result;
bool visited[MAX];
int data[MAX];
int N, K, value, current = 1;

int main()
{
	Init();

	std::cin >> N >> K;

	value = N - 1;
	if (N > K)
	{
		int mid = K + 1;

		std::cout << mid << " ";
		for (int i = 1; i <= N; ++i)
		{
			if (i == mid) continue;
			std::cout << i << " ";
		}
	}

	else
	{
		while (K)
		{
			if (K / value)
			{
				K -= value;
				visited[N] = true;
				result.push_back(N--);
			}
			else
			{
				while (visited[current]) current++;
				visited[current] = true;
				result.push_back(current++);
			}

			value--;
		}

		for (int i = current; i <= N; ++i)
		{
			if (visited[i]) continue;

			result.push_back(i);
		}
		for (auto p : result)
		{
			std::cout << p << " ";
		}
	}
}