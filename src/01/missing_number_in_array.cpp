/** Nicola Dardanis
 * 
 * Competitive Programming and Contest, a.a. 2020-2021
 * */

/**
 * Given an array C of size N-1 and given that there are numbers from 1 to N with one element missing, the missing number is to be found.
 * 
 * Input:
 * The first line of input contains an integer T denoting the number of test cases. For each test case first line contains N(size of array). The subsequent line contains N-1 array elements.
 * 
 * Output:
 * Print the missing number in array.
 * 
 * Constraints:
 * 1 ≤ T ≤ 200
 * 1 ≤ N ≤ 107
 * 1 ≤ C[i] ≤ 107
 * 
 * SOLUTION DESCRIPTION:
 * We compute the sum from 1 to N using Gauss formula n(n + 1)/2.
 * We compute the sum of the array C and subtract this sum to the one calculated before.
 * 
 * Complexity: O(n) both time and space.
 * Note: the solution with xor does not suffer the overflow problem.
 */

#include<iostream>
#include<vector>


long long missing(std::vector<int> const& vec) {
    long long sum = 0;
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        sum += *it;
    }
    int N = vec.size() + 1;
    long long gauss_sum = N * (N + 1) / 2;
    return gauss_sum - sum;
}

int xor_missing(std::vector<int> const& vec) {
    int vxor = 0;
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        vxor ^= *it;
    }
    for (int i = 1; i <= vec.size() + 1; ++i) {
        vxor ^= i;
    }
    return vxor;
}

int main() {
    int T = 0, N = 0;
    int i, j;
    std::vector<int> vec;
    std::cin >> T;
    for (i = 0; i < T; ++i) {
        std::cin >> N;
        vec.reserve(N - 1);
        for (j = 0; j < N - 1; ++j) {
            int next = 0;
            std::cin >> next;
            vec.push_back(next);
        }
        int miss = xor_missing(vec);
        std::cout << miss << std::endl;;
    }
    return 0;
}