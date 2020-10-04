/** Nicola Dardanis
 * 
 * Competitive Programming and Contest, a.a. 2020-2021
 * */

/**
 * https://www.geeksforgeeks.org/exponential-search/
 * 
 * Exponential search is a variant of binary search which involves two steps:
 * 1. Find the smallest prefix of A which contains k and has length which is a power of 2.
 * 2. Do Binary Search on this prefix to find k.
 * 
 * The first step is done by comparing k with the last number of every prefix of A which is 
 * a power of 2 until we find a larger number. We thus compare elements at positions 0, 1, 3, 7, 15..
 * unti we find the first element, at position i, such that A[i] >= k.
 * Then we conclude the second step by searching using binary search in the interval [i/2, i].
 * 
 * Exponential search has two advantages:
 * 1. can be used even if the size of A is unknown.
 * 2. requires Theta(log(j)) comparisons, where j is the position of k in A.
 */
#include<vector>
#include<iostream>
#include<algorithm>

int binary_search(std::vector<int> vec, int k, int start, int end);

int exponential_search(std::vector<int> vec, int k) {
    if (vec[0] == k) {
        return 0;
    }
    int i = 1;
    while (i < k && i < vec.size() && vec[i] < k) {
        i *= 2;
    }
    return binary_search(vec, k, i / 2, std::min(i, k));
}

int binary_search(std::vector<int> vec, int k, int start, int end) {
    if (end >= start) {
        int center = (end - start) / 2 + start;
        if (vec[center] == k) {
            return center;
        } else {
            if (vec[center] > k) {
                return binary_search(vec, k, start, center - 1);
            } else {
                return binary_search(vec, k, center + 1, end);
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
    int index = exponential_search(vec, k);
    std::cout << index << std::endl;;
    vec.clear();
    return 0;
}