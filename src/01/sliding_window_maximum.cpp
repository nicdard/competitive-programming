/** Nicola Dardanis
 * 
 * Competitive Programming and Contest, a.a. 2020-2021
 * */

/**
 * Given an array A and an integer K. Find the maximum for each and every contiguous subarray of size K.
 * 
 * Input:
 * The first line of input contains an integer T denoting the number of test cases.
 * The first line of each test case contains a single integer N denoting the size of array and the size of subarray K.
 * The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.
 * 
 * Output:
 * Print the maximum for every subarray of size k.
 * 
 * Constraints:
 * 1 ≤ T ≤ 200
 * 1 ≤ N ≤ 10^7
 * 1 ≤ K ≤ N
 * 0 ≤ A[i] <= 10^7
 * 
 * SOLUTION DESCRIPTION
 * We use an auxiliary queue to store the indexes of the maximums candidates.
 * Complexity: O(nlogk)
 */
#include<iostream>
#include<vector>
#include<deque>

template<typename T>
std::vector<T> sliding_window_maximums(std::vector<T> const& vec, int k) {
    std::vector<T> maximums;
    std::deque<int> indexes;
    maximums.reserve(vec.size() - k + 1);
    for (int i = 0; i < vec.size(); ++i) {
        while (!indexes.empty() && indexes.front() <= i - k) {
            indexes.pop_front();
        }
        while (!indexes.empty() && vec[indexes.back()] <= vec[i]) {
            indexes.pop_back();
        }
        indexes.push_back(i);
        if (i >= k - 1) {
            maximums.push_back(vec[indexes.front()]);
        }
    }
    return maximums;
}

int main() {
    int T, N, K, i, j;
    std::vector<int> vec;
    std::cin >> T;
    for (i = 0; i < T; ++i) {
        std::cin >> N;
        std::cin >> K;
        vec.reserve(N);
        for (j = 0; j < N; ++j) {
            int x = 0;
            std::cin >> x;
            vec.push_back(x);
        }
        auto maximums = sliding_window_maximums(vec, K);
        for (auto const& max : maximums) {
            std::cout << max << " ";
        }
        std::cout << std::endl;
        maximums.clear();
        vec.clear();
    }
    return 0;
}