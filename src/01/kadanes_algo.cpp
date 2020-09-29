/** Nicola Dardanis
 * 
 * Competitive Programming and Contest, a.a. 2020-2021
 * */

/** 
 * 
 * Given an array arr of N integers. Find the contiguous sub-array with maximum sum.
 * 
 * Input:
 * The first line of input contains an integer T denoting the number of test cases.
 * The description of T test cases follows. 
 * The first line of each test case contains a single integer N denoting the size of array.
 * The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.
 * 
 * Output:
 * Print the maximum sum of the contiguous sub-array in a separate line for each test case.
 * 
 * Constraints:
 * 1 ≤ T ≤ 110
 * 1 ≤ N ≤ 106
 * -107 ≤ A[i] <= 107
 * 
 * SOLUTION DESCRIPTION:
 * 
 * We use an auxiliary int var to store the maxmium sum, let's call it max and 
 * another to store the current sum of elements that we are considering. 
 * We scan the array from left to right and sum the current element to the current sum. 
 * Anytime the sum is greater than max we update the maximum. 
 * If the sum is negative, we reset the current sum to 0. This way we are ignoring all 
 * negative-sum prefixes and we consider only subarrays starting with a positive number.
 * 
 * Complexity: O(n) both for space and time.
 * Note: We could have not stored the numbers by consuming the input stream to keep the space O(1).
 *       The solution is however done this way just to provide an implementation independent from 
 *       the driver code.
 */

#include<bits/stdc++.h>

using namespace std;

int kadanes(vector<int> const& vec) {
    int max = 0, sum = 0;
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        sum += *it;
        if (sum > max) {
            max = sum;
        }
        if (sum < 0) {
            sum = 0;
        }
    }
    return max;
}

int main() {
    int T = 0;
    vector<int> vec;
    cin >> T;
    int i, j;
    for (i = 0; i < T; i++) {
        int N = 0;
        cin >> N;
        vec.reserve(N);
        for (j = 0; j < N; j++) {
            int x = 0;
            cin >> x;
            vec.push_back(x);
        }
        cout << kadanes(vec) << endl;
        vec.clear();
    }
    return 0;
}