/** Nicola Dardanis
 * 
 * Competitive Programming and Contest, a.a. 2020-2021
 * */

/**
 * Merge sort is a divide and conquer algorithm. 
 * It divides the array in two halves and sorts them recursively.
 * 
 * Complexity: O(n*log(n))
 */

#include<iostream>
#include<vector>
#include<algorithm>

template<typename T>
void merge(std::vector<T>& vec, size_t l, size_t m, size_t r) {
    size_t i = l;
    size_t j = m + 1;
    size_t k = 0;
    std::vector<uint64_t> temp((r - l) + 1);

    while (i <= m and j <= r) {
        if (vec[i] >= vec[j]) {
            temp[k++] = vec[j++];
        } else {
            temp[k++] = vec[i++];
        }
    }

    while (i <= m) {
        temp[k++] = vec[i++];
    }  
    while (j <= r) {
        temp[k++] = vec[j++];
    }

    copy(temp.begin(), temp.end(), vec.begin() + l);
}

template<typename T>
void merge_sort(std::vector<T>& vec, size_t l, size_t r) {
    if (l >= r) return;
    else {
        size_t m = (r + l) / 2;
        merge_sort(vec, l, m);
        merge_sort(vec, m + 1, r);
        merge(vec, l, m, r);
    }
}

int main() {
    int n = 0;
    std::vector<int> vec;
    std::cin >> n;
    vec.reserve(n);
    for (int i = 0; i < n; ++i) {
        int x = 0;
        std::cin >> x;
        vec.push_back(x);
    }
    merge_sort(vec, 0, vec.size() - 1);
    for (auto& el: vec) {
        std::cout << el << " ";
    }
    std::cout << std::endl;;
    vec.clear();
    return 0;
}