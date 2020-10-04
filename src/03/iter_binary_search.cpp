/** Nicola Dardanis
 * 
 * Competitive Programming and Contest, a.a. 2020-2021
 * */

/**
 * https://www.geeksforgeeks.org/binary-search/
 * 
 * Binary Search: Search a sorted array by repeatedly dividing the search interval in half. 
 * Begin with an interval covering the whole array. 
 * If the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half. 
 * Otherwise narrow it to the upper half. Repeatedly check until the value is found or the interval is empty.
 * 
 * Complexity: O(log(n), O(1) additional space.
 */
#include<iostream>
#include<vector>

int binary_search(std::vector<int> vec, int k, int start, int end) {
    while (end >= start) {
        int center = (end - start) / 2 + start;
        if (vec[center] == k) {
            return center;
        } else {
            if (vec[center] > k) {
                end = center - 1;
            } else {
                start = center + 1;
            }
        }
    }
    return -1;
}

int main() {
    int n = 0, k = 0;
    std::vector<int> vec;
    std::cin >> n;
    vec.reserve(n);
    std::cin >> k;
    for (int i = 0; i < n; ++i) {
        int x = 0;
        std::cin >> x;
        vec.push_back(x);
    }
    int index = binary_search(vec, k, 0, vec.size() - 1);
    std::cout << index << std::endl;;
    vec.clear();
    return 0;
}
