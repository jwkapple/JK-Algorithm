#include <iostream>
#include <queue>

#define pii std::pair<int, int>

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int MAX = 100 + 1;

bool visitedM[MAX][MAX], visited[MAX][MAX];
std::queue<pii> Q;
int data[MAX][MAX];
int N, M, T, mY, mX;

int main()
{
	Init();

	std::cin >> N >> M;

	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= M; ++x)
		{
			std::cin >> data[y][x];

			if (data[y][x] == 2)
			{
				mY = y;
				mX = x;
			}
		}
	}

	Q.push(pii(1, 1));

	bool isDone = false;

	int maken = 0;

	std::queue<pii> mQ;
	while (!mQ.empty() && !isDone)
	{
		int size = mQ.size();

		for (int i = 0; i < size; ++i)
		{
			auto [y, x] = mQ.front();
			mQ.pop();

			if (visitedM[y][x])
				continue;

			visitedM[y][x] = true;

			if (data[y][x] == 2)
			{
				isDone = true;
				break;
			}

			for (int j = 0; j < 4; ++j)
			{
				int Y = y + dir[j][0];
				int X = x + dir[j][0];

				if (Y <= N && Y > 0 && X <= M && X > 0)
				{
					if (!visited[Y][X])
						mQ.push(pii(Y, X));
				}
			}
		}

		maken++;
	}

	if (isDone)
		maken--;
	else
		maken = -1;

	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= M; ++x)
		{
			visitedM[y][x] = false;
		}
	}
	std::queue<pii> mmQ;
	mmQ.push(pii(mY, mX));

	isDone = false;

	int mToC = 0;
	while (!mmQ.empty() && !isDone)
	{
		int size = mmQ.size();

		for (int i = 0; i < size; ++i)
		{
			auto [y, x] = mmQ.front();
			mmQ.pop();

			if (visitedM[y][x])
				continue;

			visitedM[y][x] = true;

			if (y == N && x == M)
			{
				isDone = true;
				break;
			}
		}

		mToC++;
	}

	if (isDone)
		mToC--;
	else
		mToC = -1;

	Q.push(pii(1, 1));

	isDone = false;

	int value = 0;
	while (!Q.empty() && !isDone)
	{
		int size = Q.size();
		Q.pop();

		for (int i = 0; i < size; ++i)
		{
			auto [y, x] = Q.front();
			Q.pop();

			if (visited[y][x])
				continue;

			visited[y][x] = true;

			if (y == N && x == M)
			{
				isDone = true;
				break;
			}
		}

		value++;
	}

	if (isDone)
		value--;
	else
		value = -1;

	if (maken == -1 || mToC == -1)
	{
		if (value == -1)
		{
			std::cout << "Fail";
		}
		else
		{
			if (value <= T)
			{
				std::cout << value;
			}
			else
				std::cout << "Fail";
		}
	}
	else
	{
		int result = maken + mToC;

		result = result > value ? value : result;

		if (result <= T)
			std::cout << result;
		else
			std::cout << "Fail";
	}
}