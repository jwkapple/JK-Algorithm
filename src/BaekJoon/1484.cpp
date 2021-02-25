#include <iostream>
#include <queue>
#include <vector>

#define D(num) num * num
void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

std::priority_queue<int, std::vector<int>, std::greater<int>> result;
int left = 1, right = 1, G;

int main() {

	Init();

	std::cin >> G;

	while (true)
	{
		if (left + 1 == right && D(left) + G < D(right)) break;

		if (D(right) - D(left) < G) right++;
		else left++;

		if (D(right) - D(left) == G) result.push(right);
	}

	if (!(result.size())) std::cout << -1;
	else
	{
		while (!result.empty())
		{
			std::cout << result.top() << "\n";
			result.pop();
		}
	}
}