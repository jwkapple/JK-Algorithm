#include <iostream>
#include <vector>
#include <algorithm>

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

struct Room
{
	int Current;
	int Differ;
	int Stick;
};
const int MAX = 1e5 + 1;

int N, M, L;

int restroom[MAX];
std::vector<Room> heap;

void swap(Room& A, Room& B)
{
	Room tmp = A;
	A.Current = B.Current; A.Differ = B.Differ; A.Stick = B.Stick;
	B.Current = tmp.Current; B.Differ = tmp.Differ; B.Stick = tmp.Stick;
}
void insert(std::vector<Room>& heap, Room data)
{
	if (heap.size() == 0)
	{
		heap.push_back(data);
		return;
	}

	heap.push_back(data);

	int now = heap.size();
	int parent = now / 2;

	while (parent > 0)
	{
		if (heap[now - 1].Current > heap[parent - 1].Current)
		{
			swap(heap[now - 1], heap[parent - 1]);
			now = parent;
			parent = now / 2;
		}

		else break;
	}
}

Room pop(std::vector<Room>& heap)
{
	Room min = heap[0];
	heap[0] = heap.back();
	heap.pop_back();

	int now = 1;
	int left = now * 2;
	int right = now * 2 + 1;

	while (left <= heap.size())
	{
		if (right <= heap.size())
		{
			if (heap[left - 1].Current > heap[right - 1].Current)
			{
				if (heap[left - 1].Current > heap[now - 1].Current)
				{
					swap(heap[left - 1], heap[now - 1]);

					now = left;
					left = now * 2;
					right = now * 2 + 1;
				}

				else break;
			}

			else
			{
				if (heap[right - 1].Current > heap[now - 1].Current)
				{
					swap(heap[right - 1], heap[now - 1]);

					now = right;
					left = now * 2;
					right = now * 2 + 1;
				}

				else break;
			}
		}

		else
		{
			if (heap[left - 1].Current > heap[now - 1].Current)
			{
				swap(heap[left - 1], heap[now - 1]);

				now = left;
				left = now * 2;
				right = now * 2 + 1;
			}

			else break;
		}
	}

	return min;
}
int main()
{
	Init();

	std::cin >> N >> M >> L;

	for (int i = 1;i <= N; i++)
	{
		std::cin >> restroom[i];
	}

	restroom[0] = 0;
	restroom[N + 1] = L;

	std::sort(restroom, restroom + N + 2);

	for (int i = 0;i <= N; i++)
	{
		Room tmp;
		tmp.Differ = restroom[i + 1] - restroom[i];
		tmp.Stick = 1;
		tmp.Current = tmp.Differ;

		insert(heap, tmp);
	}

	for (int i = 0;i < M; i++)
	{
		Room max = pop(heap);
		max.Stick++;
		if (max.Differ % max.Stick != 0) max.Current = max.Differ / max.Stick + 1;

		else max.Current = max.Differ / max.Stick;

		insert(heap, max);
	}

	Room result = pop(heap);

	std::cout << result.Current;
}