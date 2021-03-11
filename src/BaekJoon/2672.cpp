#include <iostream>
#include <vector>
#include <queue>

#define pbb std::pair<double, double>
#define info std::pair<double, int>
void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

std::priority_queue<info, std::vector<info>, std::greater<info>> pq; // xÁÂÇ¥, ID
std::priority_queue<info, std::vector<info>, std::greater<info>> current; // yÁÂÇ¥, ID
std::vector<pbb> ID;
bool visited[32];
double left = 0.0, result = 0.0;
int N;

double func(double x, std::priority_queue<info, std::vector<info>, std::greater<info>> cur)
{
	double w = x - left;
	double total = 0;
	cur.push(info(1e9, 0));

	left = 0;
	double right = 0;

	while (!cur.empty())
	{
		double L = cur.top().first;
		int id = cur.top().second; cur.pop();
		if (!visited[id]) continue;

		double R = ID[id].second;
		if (L <= right)
		{
			right = right > R ? right : R;
		}
		else
		{
			total += right - left;
			left = L, right = R;
		}
	}

	left = x;
	return w * total;
}

int main()
{

	Init();

	std::cin >> N;

	ID.push_back(pbb(0, 0));
	current.push(info(0, 0));
	visited[0] = true;

	double x, y, w, h;
	for (int i = 1; i <= N; ++i)
	{
		std::cin >> x >> y >> w >> h;

		ID.push_back(pbb(y, y + h));
		pq.push(info(x, i)), pq.push(info(x + w, i * -1));
	}

	while (!pq.empty())
	{
		double x = pq.top().first;
		int id = pq.top().second;

		pq.pop();

		result += func(x, current);

		if (id > 0)
		{
			current.push(info(ID[id].first, id));
			visited[id] = true;
		}
		else
		{
			id *= -1;
			visited[id] = false;
		}
	}

	if (result - static_cast<int>(result))
	{
		std::cout << std::fixed;
		std::cout.precision(2);
		std::cout << result;
	}

	else std::cout << result;
}