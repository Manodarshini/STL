#include <iostream>
#include <vector>
#include <algorithm>

template <typename Container>

typename Container::value_type getMedian(Container container) 
{
    // Sort the container in ascending order
    std::sort(container.begin(), container.end());
    size_t size = container.size();
    if (size % 2 == 0) 
    {
        // If the container has an even number of elements, take the average of two middle elements
        auto middle1 = container.begin() + (size / 2) - 1;
        auto middle2 = container.begin() + (size / 2);
        return (*middle1 + *middle2) / 2;
    } 
    else 
    {
        // If the container has an odd number of elements, return the middle element
        return container[size / 2];
    }
}

int main() 
{
    std::vector<int> numbers1 = {10, 5, 20, 15, 30};
    std::vector<int> numbers2 = {9, 4, 15, 8, 22, 6};
    int median1 = getMedian(numbers1);
    int median2 = getMedian(numbers2);
    std::cout << "Median of numbers1: " << median1 << std::endl;
    std::cout << "Median of numbers2: " << median2 << std::endl;
    return 0;
}
