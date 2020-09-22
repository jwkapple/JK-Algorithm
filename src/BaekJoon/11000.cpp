#include <iostream>
#include <algorithm>
#include <vector>

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

std::vector<std::pair<int, int>> heap;
std::vector<int> tmp;

int N;


void swapI(int& A, int& B)
{
	int tmp = A;
	A = B;
	B = tmp;
}
void InsertI(std::vector<int>& heap, int data)
{
	if (heap.empty())
	{
		heap.push_back(data);
		return;
	}

	heap.push_back(data);

	int now = heap.size();
	int parent = now / 2;

	while (parent > 0)
	{
		if (heap[now - 1] < heap[parent - 1])
		{
			swapI(heap[now - 1], heap[parent - 1]);
			now = parent;
			parent = now / 2;
		}
		else break;
	}
}
void PopI(std::vector<int>& heap)

{
	if (heap.empty()) return;

	heap[0] = heap.back();
	heap.pop_back();

	int size = heap.size();
	int now = 1;
	int left = now * 2;
	int right = now * 2 + 1;

	while (left <= size)
	{
		if (right <= size)
		{
			if (heap[right - 1] < heap[left - 1])
			{
				if (heap[now - 1] > heap[right - 1])
				{
					swapI(heap[now - 1], heap[right - 1]);

					now = right;
					left = now * 2;
					right = now * 2 + 1;
				}
				else break;
			}

			else
			{
				if (heap[now - 1] > heap[left - 1])
				{
					swapI(heap[now - 1], heap[left - 1]);

					now = left;
					left = now * 2;
					right = now * 2 + 1;
				}
				else break;
			}
		}

		else
		{
			if (heap[now - 1] > heap[left - 1])
			{
				swapI(heap[now - 1], heap[left - 1]);

				now = left;
				left = now * 2;
				right = now * 2 + 1;
			}
			else break;
		}
	}
}

int main()
{
	Init();

	std::cin >> N;

	int start, end;
	for (int i = 0;i < N; i++)
	{
		std::cin >> start >> end;
		heap.push_back(std::make_pair(start, end));
	}

	std::sort(heap.begin(), heap.begin() + heap.size());

	InsertI(tmp, heap[0].second);

	for (int i = 1;i < N; i++)
	{
		std::pair<int, int> cur = heap[i];

		if (tmp.front() <= cur.first) PopI(tmp);

		InsertI(tmp, cur.second);
	}

	std::cout << tmp.size();
}
