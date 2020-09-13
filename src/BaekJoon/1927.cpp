#include <iostream>
#include <vector>

void Init() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
}


int N;
std::vector<int> result;
std::vector<int> heap;

void swap(int& A, int& B)
{
	int tmp = A;
	A = B;
	B = tmp;
}

void add(std::vector<int>& heap, int data)
{
	if (heap.size() == 0)
	{
		heap.push_back(data);
		return;
	}

	heap.push_back(data);

	int current = heap.size();
	int parent = current / 2;

	while (parent > 0)
	{
		if (heap[current - 1] < heap[parent - 1])
		{
			swap(heap[current - 1], heap[parent - 1]);
			current = parent;
			parent = current / 2;
		}

		else break;
	}
}

void pop(std::vector<int>& heap)
{
	if (heap.size() == 0)
	{
		result.push_back(0);
		return;
	}

	int min = heap[0];

	heap[0] = heap.back();
	heap.pop_back();

	int current = 1;
	int left = current * 2;
	int right = current * 2 + 1;

	while (left <= heap.size())
	{
		if (right <= heap.size())
		{
			if (heap[left - 1] > heap[right - 1])
			{
				if (heap[current - 1] > heap[right - 1])
				{
					swap(heap[right - 1], heap[current - 1]);

					current = right;
					left = current * 2;
					right = current * 2 + 1;
				}

				else break;
			}
			else
			{
				if (heap[current - 1] > heap[left - 1])
				{
					swap(heap[left - 1], heap[current - 1]);

					current = left;
					left = current * 2;
					right = current * 2 + 1;
				}

				else break;
			}
		}

		else
		{
			if (heap[current - 1] > heap[left - 1])
			{
				swap(heap[current - 1], heap[left - 1]);

				current = left;
				left = current * 2;
				right = current * 2 + 1;
			}

			else break;
		}
	}

	result.push_back(min);
}

int main()
{
	Init();

	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		std::cin >> num;

		if (num == 0) pop(heap);
		else add(heap, num);
	}

	for (int i = 0; i < result.size(); i++)
	{
		std::cout << result[i] << "\n";
	}
}