#include <iostream>
#include <vector>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);#include <iostream>
#include <queue>
#include <vector>

#define pii std::pair<int, int>
		void Init()
	{
		std::ios_base::sync_with_stdio(false);
		std::cin.tie(NULL); std::cout.tie(NULL);
	}

	const int MAX = 1e4 + 1;


	std::priority_queue<pii, std::vector<pii>, std::greater<pii>> Q;
	std::priority_queue<int, std::vector<int>, std::greater<int>> result;
	int data[MAX], pid[MAX], arr[MAX], name[MAX];
	int N, cur = 0, end = 0;

	int find(int from, int to, int num)
	{
		if (from == to) return from;
		if (from + 1 == to)
		{
			if (data[from] > num) return from;
			else return to;
		}

		int mid = (from + to) / 2;
		if (data[mid] > num) return find(from, mid, num);
		else return find(mid + 1, to, num);
	}
	int main()
	{
		Init();

		std::cin >> N;

		data[0] = -1;

		int tmp;
		for (int i = 0; i < N; ++i) { std::cin >> name[i]; arr[name[i]] = i; }
		for (int i = 0; i < N; ++i)
		{
			std::cin >> tmp;

			Q.push(pii(arr[tmp], i));
		}

		while (!Q.empty())
		{
			auto[from, to] = Q.top(); Q.pop();

			end = end > from ? end : from;
			if (data[cur] < to)
			{
				data[++cur] = to;
				pid[from] = cur;
			}
			else
			{
				tmp = find(0, cur, to);
				data[tmp] = to;
				pid[from] = tmp;
			}
		}

		std::cout << cur << "\n";

		for (int i = end; i >= 0; --i)
		{
			if (!pid[i]) continue;
			if (pid[i] == cur)
			{
				result.push(name[i]);
				cur--;
			}
		}

		while (!result.empty())
		{
			std::cout << result.top() << " ";
			result.pop();
		}
	}

