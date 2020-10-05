#include <iostream>
#include <queue>

#ifdef TEST
#include <fstream>
std::ifstream readFile;

char c;
inline int toInt() { return static_cast<int>(c) - '0'; }
#endif // TEST

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

const int MAX = 1e6 + 1;

std::queue<int> Q;
int visited[MAX];
int result = -1;

int F, S, G; // F : total floor, G : StartLink Floor, S : Gangho Floor
int U, D;	 // U : move upper,  D : move lower

void bfs()
{
	while (!Q.empty())
	{
		for (int i = 0; i < Q.size(); i++)
		{
			auto current = Q.front();
			Q.pop();

			if (current == G)
			{
				result = visited[current];
				break;
			}

			int up = current + U;
			int down = current - D;

			if (up <= F)
			{
				if (!visited[up])
				{
					Q.push(up);
					visited[up] = visited[current] + 1;
				}
			}

			if (down >= 1)
			{
				if (!visited[down])
				{
					Q.push(down);
					visited[down] = visited[current] + 1;
				}
			}
		}
	}
}

int main() {

	Init();

	std::cin >> F >> S >> G >> U >> D;

	Q.push(S);
	visited[S] = 1;

	bfs();

	if (result == -1) std::cout << "use the stairs";
	else std::cout << result - 1;
}