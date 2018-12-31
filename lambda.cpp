#include <iostream>
#include <algorithm>
 
/*
[](int x) {
        std::cout<<x<<" ";
    }*/

int main() {
    int arr[] = { 1, 2, 3, 4, 5 };
 
    std::for_each(arr, arr + sizeof(arr) / sizeof(int), [](int x) {
            std::cout<<x<<" ";
        });
 
    std::cout << std::endl;
 
}