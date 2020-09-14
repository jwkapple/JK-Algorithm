#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}

int N, M;
int max;
int result = 0;
std::vector<int> leftHeap;
std::vector<int> rightHeap;

void swap(int& A, int& B)
{
	int tmp = A;
	A = B;
	B = tmp;
}
void insert(std::vector<int>& heap, int data)
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
		if (heap[now - 1] > heap[parent - 1])
		{
			swap(heap[now - 1], heap[parent - 1]);
			now = parent;
			parent = now / 2;
		}

		else break;
	}
}

int pop(std::vector<int>& heap)
{
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
			if (heap[left - 1] < heap[right - 1])
			{
				if (heap[right - 1] > heap[now - 1])
				{
					swap(heap[right - 1], heap[now - 1]);

					now = right;
					left = now * 2;
					right = now * 2 + 1;
				}

				else break;
			}

			else
			{
				if (heap[left - 1] > heap[now - 1])
				{
					swap(heap[left - 1], heap[now - 1]);

					now = left;
					left = now * 2;
					right = now * 2 + 1;
				}

				else break;
			}
		}

		else
		{
			if (heap[left - 1] > heap[now - 1])
			{
				swap(heap[left - 1], heap[now - 1]);

				now = left;
				left = now * 2;
				right = now * 2 + 1;
			}

			else break;
		}
	}

	return max;
}
int main()
{
	Init();

	std::cin >> N >> M;

	int tmp;

	for (int i = 0;i < N; i++)
	{
		std::cin >> tmp;
		if (tmp < 0) insert(leftHeap, std::abs(tmp));
		else insert(rightHeap, tmp);
	}

	if (!leftHeap.empty())
	{
		if (!rightHeap.empty())
		{
			int maxLeft = leftHeap.front();
			int maxRight = rightHeap.front();

			if (maxLeft < maxRight)
			{
				result += pop(rightHeap);
				for (int i = 0;i < M - 1; i++)
				{
					if (!rightHeap.empty()) pop(rightHeap);
				}
			}
			else
			{
				result += pop(leftHeap);
				for (int i = 0;i < M - 1; i++)
				{
					if (!leftHeap.empty()) pop(leftHeap);
				}
			}
		}
		else
		{
			result += pop(leftHeap);
			for (int i = 0;i < M - 1; i++)
			{
				if (!leftHeap.empty()) pop(leftHeap);
			}
		}
	}
	else
	{
		if (!rightHeap.empty())
		{
			result += pop(rightHeap);
			for (int i = 0;i < M - 1; i++)
			{
				if (!rightHeap.empty()) pop(rightHeap);
			}
		}
	}

	while (!leftHeap.empty())
	{
		result += pop(leftHeap) * 2;
		for (int i = 0;i < M - 1; i++)
		{
			if (!leftHeap.empty()) pop(leftHeap);
		}
	}

	while (!rightHeap.empty())
	{
		result += pop(rightHeap) * 2;
		for (int i = 0;i < M - 1; i++)
		{
			if (!rightHeap.empty()) pop(rightHeap);
		}
	}

	std::cout << result;
}