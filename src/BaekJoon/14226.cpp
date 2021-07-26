#include <iostream>
#include <queue>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e3 + 1;

std::queue<pii> data; // value, clipboard
bool visited[MAX][MAX];

int S, T, C = -1, result = 0, max = 1e9;

int main()
{
	Init();

	std::cin >> S;

	data.push(pii(1, 0));

	int size;
	while (!data.empty())
	{
		size = data.size();
		for (int i = 0; i < size; ++i)
		{
			auto[value, C] = data.front(); data.pop();

			if (value == S) { result = T; break; }

			if (value > S)
			{
				if (max < C) continue;

				max = C;
				data.push(pii(value - 1, C));
			}
			else
			{
				if (visited[value][C] || value == 0) continue;
				visited[value][C] = true;

				if (C) data.push(pii(value + C, C));
				if (value > 0) data.push(pii(value - 1, C));
				data.push(pii(value, value));
			}
		}

		if (result) break;

		T++;
	}

	std::cout << result;
}