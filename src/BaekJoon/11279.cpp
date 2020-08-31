#include <iostream>
#include <vector>

const int MAX = 1e5 + 1;
int N;

std::vector<int> result;
std::vector<int> heap;

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void Insert(std::vector<int>& heap, int data)
{
	if (heap.empty())
	{
		heap.push_back(data);
		return;
	}

	heap.push_back(data);
	int current = heap.size();
	int parent = current / 2;

	while (parent > 0)
	{
		if (heap[current - 1] > heap[parent - 1])
		{
			swap(heap[current - 1], heap[parent - 1]);
			current = parent;
			parent = current / 2;
		}

		else break;
	}
}

void Pop(std::vector<int>& heap)
{
	if (heap.empty())
	{
		result.push_back(0);
		return;
	}

	int max = heap[0];
	heap[0] = heap.back();
	heap.pop_back();

	int now = 1;
	int left = now * 2;
	int right = now * 2 + 1;

	while (left <= heap.size())
	{
		if (right <= heap.size())
		{
			if (heap[right - 1] > heap[left - 1])
			{
				if (heap[right - 1] < heap[now - 1]) break;
				swap(heap[now - 1], heap[right - 1]);

				now = right;
				left = now * 2;
				right = now * 2 + 1;
			}
			else
			{
				if (heap[left - 1] < heap[now - 1]) break;
				swap(heap[left - 1], heap[now - 1]);

				now = left;
				left = now * 2;
				right = now * 2 + 1;
			}
		}
		else
		{
			if (heap[left - 1] < heap[now - 1]) break;
			swap(heap[left - 1], heap[now - 1]);

			now = left;
			left = now * 2;
			right = now * 2 + 1;
		}
	}

	result.push_back(max);
}
int main()
{
	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		int instruct;
		std::cin >> instruct;

		if (instruct == 0) Pop(heap);
		else Insert(heap, instruct);
	}

	for (int i = 0;i < result.size(); i++)
	{
		std::cout << result[i] << "\n";
	}
}