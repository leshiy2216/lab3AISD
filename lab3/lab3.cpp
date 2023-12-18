#include <iostream>
#include <vector>
#include <random>
#define SIZE 1000

using namespace std;

struct stats {
	size_t comparison_count = 0;
	size_t copy_count = 0;

	friend stats operator+(const stats& left, const stats& right);
};


stats bubble_sort(std::vector<int>& arr) 
{
	stats stats;

	size_t length = arr.size();
	for (size_t i = 0; i < length - 1; i++) 
	{
		for (size_t j = 0; j < length - i - 1; j++) 
		{
			if (arr[j] > arr[j + 1]) 
			{
				swap(arr[j + 1], arr[j]);
				stats.copy_count += 1;
			}
			stats.comparison_count++;
		}
	}
	return stats;
}

stats quick_sort(std::vector<int>& arr, int left, int right) 
{
	stats stats;
	int i = left, j = right;
	int main_element = arr[left];

	while (i <= j) 
	{
		while (arr[i] < main_element) 
		{
			stats.comparison_count++;
			i++;
		}
		while (arr[j] > main_element) 
		{
			stats.comparison_count++;
			j--;
		}
		if (i <= j) 
		{
			swap(arr[i], arr[j]);
			i++;
			j--;

			stats.copy_count += 1;
		}
	}

	if (left < j)
		stats = stats + quick_sort(arr, left, j);
	if (i < right)
		stats = stats + quick_sort(arr, i, right);

	return stats;
}

void heapify(std::vector<int>& arr, int size, int i, stats& stats)
{
	size_t largest = i;

	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < size && arr[left] > arr[largest]) 
	{
		largest = left;
		stats.comparison_count++;
	}

	if (right < size && arr[right] > arr[largest]) 
	{
		largest = right;
		stats.comparison_count++;
	}

	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		stats.copy_count += 1;
		heapify(arr, size, largest, stats);
	}
}

stats heap_sort(std::vector<int>& arr)
{
	stats stats;
	int size = arr.size();

	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(arr, size, i, stats);

	for (int i = size - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		stats.copy_count += 1;
		heapify(arr, i, 0, stats);
	}

	return stats;
}

int main() 
{
	return 0;
}