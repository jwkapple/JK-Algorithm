#include <iostream>
#include <string>
#include <deque>
void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

std::deque<char> dq;
std::string data;
int N, K;

int main()
{
	Init();

	std::cin >> N >> K;

	int S = N - K;
	std::cin >> data;

	for (int i = 0; i < data.size(); ++i)
	{
		while (K && !dq.empty() && dq.back() < data[i])
		{
			dq.pop_back();

			K--;
		}

		dq.push_back(data[i]);
	}


	for (int i = 0;i < S; ++i)
	{
		std::cout << static_cast<int>(dq.front() - 48);
		dq.pop_front();
	}
}