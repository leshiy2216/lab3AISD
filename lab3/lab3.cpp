#include <iostream>
#include <vector>

struct stats {
    size_t comparison_count = 0;
    size_t copy_count = 0;
};

void bubbleSort(std::vector<int>& arr, stats& statistics) {
    size_t n = arr.size();
    bool swapped;
    for (size_t i = 0; i < n - 1; ++i) {
        swapped = false;
        for (size_t j = 0; j < n - i - 1; ++j) {
            ++statistics.comparison_count;
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                ++statistics.copy_count;
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    std::vector<int> array = { 64, 34, 25, 12, 22, 11, 90 };
    stats statistics;

    bubbleSort(array, statistics);
    for (const auto& element : array) {
        std::cout << element << " ";
    }
    std::cout << "Количество сравнений: " << statistics.comparison_count << "\n";
    std::cout << "Количество копирований: " << statistics.copy_count << "\n";

    return 0;
}
