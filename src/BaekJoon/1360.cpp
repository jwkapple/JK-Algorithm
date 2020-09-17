#include <iostream>
#include <stack>
#include <string>

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

struct Instruct
{
	int Second;
	bool Inst; // true :: type, false :: undo
	int Num;
	char Alpha;

	Instruct() {};
	Instruct(int second, bool inst, int num) : Second(second), Inst(inst), Num(num) {}
	Instruct(int second, bool inst, char alpha) : Second(second), Inst(inst), Alpha(alpha) {}
};

int N;
std::stack<Instruct> s;
std::stack<char> result;

int main()
{
	Init();

	std::cin >> N;

	for (int i = 0;i < N; i++)
	{
		std::string instruct;
		int second;

		std::cin >> instruct;

		if (instruct == "type")
		{
			char tmp;
			std::cin >> tmp >> second;
			s.push(Instruct(second, true, tmp));
		}

		else
		{
			int num;
			std::cin >> num >> second;
			s.push(Instruct(second, false, num));
		}
	}

	while (!s.empty())
	{
		Instruct current = s.top(); s.pop();

		switch (current.Inst)
		{

		case true: result.push(current.Alpha); break;

		case false:
			int differ = current.Second - current.Num;
			while (!s.empty())
			{
				int second = s.top().Second;
				if (second < differ) break;
				s.pop();
			}
			break;
		}
	}

	while (!result.empty())
	{
		std::cout << result.top();
		result.pop();
	}
}