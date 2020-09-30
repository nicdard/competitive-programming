/** Nicola Dardanis
 * 
 * Competitive Programming and Contest, a.a. 2020-2021
 * */

/**
 * Given an array arr[] of N non-negative integers representing height of blocks at index i as Ai where the width of each block is 1. Compute how much water can be trapped in between blocks after raining.
 * Structure is like below:
 * |  |
 * |_|
 * We can trap 2 units of water in the middle gap.
 * 
 * Input:
 * The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. Each test case contains an integer N denoting the size of the array, followed by N space separated numbers to be stored in array.
 * Output:
 * Output the total unit of water trapped in between the blocks.
 * Constraints:
 * 1 <= T <= 100
 * 3 <= N <= 10^7
 * 0 <= Ai <= 10^8
 * 
 * SOLUTION DESCRIPTION:
 * We locate the maximum of the array.
 * We scan left to right until the maximum, keeping the current maximum in a temp variable start. 
 * Each time we find a less greater element than the current maximum, we add to total amount of trapped water
 * the start - current value. Indeed, the presence of a maximum in the array to the right of start, assure 
 * that this quantity will be anyway considered in the total sum. On the other hand, if we find a greater element
 * than start, we update start and add nothing to the total amount. 
 * We can easily imagine this way of proceding as a pool finding method.
 * We do the same left to right.
 * 
 * Complexity: O(n) both for space and time.
 */

#include<vector>
#include<iostream>

int locate_maximum(std::vector<int> const& vec) {
    int max = 0, max_index = -1;
    for (int i = 0; i < vec.size(); ++i) {
        if (max < vec[i]) {
            max = vec[i];
            max_index = i;
        }
    }
    return max_index;
}

long trapped_water(std::vector<int> const& vec) {
    int max_index = locate_maximum(vec);
    long total = 0;
    int start = 0, i = 0;
    for (i = 0; i < max_index; ++i) {
        if (vec[i] > start) {
            start = vec[i];
        } else {
            total += start - vec[i];    
        }
    }
    for (i = vec.size() - 1, start = 0; i > max_index; --i) {
        if (vec[i] > start) {
            start = vec[i];
        } else {
            total += start - vec[i];
        }
    }
    return total;
}
 
int main() {
    int T = 0, N = 0, i = 0;
    std::vector<int> vec;
    std::cin >> T;
    for ( ; T > 0; --T) {
        std::cin >> N;
        vec.reserve(N);
        for ( ; N > 0; --N) {
            int x = 0;
            std::cin >> x;
            vec.push_back(x);
        }
        long total = trapped_water(vec);
        std::cout << total;
        vec.clear(); 
    }
    return 0;
}