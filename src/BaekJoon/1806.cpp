#include <iostream>
#include <climits>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e5 + 1;

int data[MAX];

int left = 0, right = 0;
int N, S, result = INT_MAX;

int main()
{
	Init();

	std::cin >> N >> S;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> data[i];
	}

	int current = data[0], length = 1;
	while (left != N)
	{
		if (right == N - 1)
		{
			if (current >= S)
			{
				result = result > length ? length : result;
				current -= data[left++];
				length--;
			}
			else break;
		}
		else
		{
			if (left == right)
			{
				current += data[++right];
				length++;
			}

			if (current >= S)
			{
				result = result > length ? length : result;
				current -= data[left++];
				length--;
			}
			else
			{
				current += data[++right];
				length++;
			}
		}
	}

	if (result == INT_MAX) std::cout << 0;
	else std::cout << result;
}