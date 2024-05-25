#include<bits/stdc++.h>
using namespace std;

class DynamicArray {
public:
    int array;
    int resize_fact;

public:
    DynamicArray(int resize_fact = 2) : resize_fact(resize_fact) {}

    void insert_at_index(int index, int value) {
        if (index < 0 || index > array.size()) {
            throw std::out_of_range("Index out of bounds");
        }
        array.insert(array.begin() + index, value);
    }

    void delete_at_index(int index) {
        if (index < 0 || index >= array.size()) {
            throw std::out_of_range("Index out of bounds");
        }
        array.erase(array.begin() + index);
    }

    int get_size() const {
        return array.size();
    }

    bool is_empty() const {
        return array.empty();
    }

    void reverse() {
        std::reverse(array.begin(), array.end());
    }

    void append(int value) {
        array.push_back(value);
    }

    int get_middle_element() const {
        if (array.empty()) {
            return -1; 
        }
        int mid_index = array.size() / 2;
        return array[mid_index];
    }

    void display() const {
        for (int value : array) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    DynamicArray dynamicArray;

    dynamicArray.append(11);
    dynamicArray.append(20);
    dynamicArray.append(0);
    dynamicArray.display();

    dynamicArray.insert_at_index(1, 4);
    dynamicArray.display();

    dynamicArray.delete_at_index(2);
    dynamicArray.display();

    dynamicArray.reverse();
    dynamicArray.display();

    cout << "Middle element: " << dynamicArray.get_middle_element() << std::endl;

    return 0;
}
