#include <iostream>
#include <vector>
#include <queue>

int findKthSmallest(const std::vector<int>& arr, int k)
{
    std::priority_queue<int> maxHeap;
    
    for (int num : arr) 
    {
        maxHeap.push(num);
        if (maxHeap.size() > k) 
        {
            maxHeap.pop();
        }
    }

    return maxHeap.top();
}

int main() {
    std::vector<int> arr = {9, 4, 7, 2, 10, 5, 1};
    int k;
    std::cout << "Enter the value of K (1-based index): ";
    std::cin >> k;

    if (k <= 0 || k > arr.size()) 
    {
        std::cerr << "Invalid value of K. K must be between 1 and " << arr.size() << "." << std::endl;
        return 1;
    }

    int kthSmallest = findKthSmallest(arr, k);
    std::cout << "The Kth smallest element is: " << kthSmallest << std::endl;

    return 0;
}
