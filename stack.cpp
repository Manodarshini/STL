#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

template <typename T>
class CustomStack {
private:
    std::vector<T> data;

public:
    void push(const T& value) {
        data.push_back(value);
    }

    void pop() {
        if (data.empty()) {
            throw std::runtime_error("CustomStack is empty. Cannot perform pop.");
        }
        data.pop_back();
    }

    T& top() {
        if (data.empty()) {
            throw std::runtime_error("CustomStack is empty. Cannot access top.");
        }
        return data.back();
    }

    const T& top() const {
        if (data.empty()) {
            throw std::runtime_error("CustomStack is empty. Cannot access top.");
        }
        return data.back();
    }

    bool empty() const {
        return data.empty();
    }

    size_t size() const 
    {
        return data.size();
    }
};

int main() 
{
    CustomStack<int> myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    std::cout<< "Stack size: "<<myStack.size()<<std::endl;
    std::cout<< "Top element: "<<myStack.top()<<std::endl;
    myStack.pop();
    std::cout<< "After pop, Top element: "<<myStack.top()<<std::endl;
    myStack.push(40);
    std::cout<< "After push, Stack size: "<<myStack.size()<<std::endl;
    std::cout<< "After push, Top element: "<<myStack.top()<<std::endl;
    return 0;
}
