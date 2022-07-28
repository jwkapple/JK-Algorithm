#include <iostream>
#include <queue>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1001;

std::vector<int> result[MAX];
int T, M;

int main()
{
	Init();

	std::cin >> T;
	int tt = T;

	while (T--)
	{
		std::priority_queue<int> pq;
		std::vector<int> data;

		data.push_back(0);
		std::cin >> M;

		int tmp, cmp = 0;
		for (int i = 1; i <= M; ++i)
		{
			std::cin >> tmp;
			data.push_back(tmp);
			pq.push(tmp);

			if (i % 2)
			{
				cmp = i / 2;
				std::vector<int> out;
				while (cmp--)
				{
					out.push_back(pq.top());
					pq.pop();
				}
				
				result[tt - T].push_back(pq.top());
				for (int i = 0; i < out.size(); ++i) pq.push(out[i]);
			}
		}
	}

	for (int i = 1;i <= tt; ++i)
	{
		std::cout << result[i].size() << "\n";
		for (int j = 1; j <= result[i].size(); ++j)
		{
			std::cout << result[i][j - 1] << " ";
			if (!(j % 10)) std::cout << "\n";
		}

		std::cout << "\n";
	}
}