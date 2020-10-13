/** Nicola Dardanis
 * 
 * Competitive Programming and Contest, a.a. 2020-2021
 * */

/**
 * https://www.spoj.com/problems/INVCNT/
 * 
 * Let A[0...n - 1] be an array of n distinct positive integers. 
 * If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A.
 * Given n and an array A your task is to find the number of inversions of A.
 * 
 * Input
 * The first line contains t, the number of testcases followed by a blank space. 
 * Each of the t tests start with a number n (n <= 200000). Then n + 1 lines follow. 
 * In the ith line a number A[i - 1] is given (A[i - 1] <= 10^7). The (n + 1)th line is a blank space.
 * 
 * Output
 * For every test output one line giving the number of inversions of A.
 * 
 * SOLUTION DESCRIPTION:
 * We use the merge sort to sort the element while counting the number of inversions.
 * We have a the nice property that every time we consider a merge operation the subarrays
 * are ordered, so neither the left nor the right one contain inverions. Thus the inverions
 * are to be found in the merge step. While performing the merge step we can rely on the fact 
 * that every time an element of the left subarray is > an element of the right one, than
 * there is a number of inversions that is equal to the size of the left subarray - the current 
 * left index (all elements in this portion of the array are indeed greater than the ones on the
 * right subarray).
 * 
 * Complexity: O(nlog(n)) time and O(n) space (auxiliary vector needed to perform the merge step)
 */

#include<iostream>
#include<vector>

struct res {
    std::vector<int>& a;
    int inversions;
};

struct res sort_count_inversion(std::vector<int>& a, int start, int end);
struct res count_split(std::vector<int>& a, int start, int end);

struct res count_split(std::vector<int>& a, int start, int center, int end) {
    int left = start;
    int right = center + 1;    
    struct res result = { a, 0 };
    std::vector<int> temp;
    temp.reserve(end - start);
    while (left <= center && right <= end) {
        if (a[left] <= a[right]) {
            temp.push_back(a[left]);
            ++left;
        } else {
            temp.push_back(a[right]);
            result.inversions += (center - left + 1);
            ++right;
        }
    }
    while (left <= center) {
        temp.push_back(a[left++]);
    }
    while (right <= end) {
        temp.push_back(a[right++]);
    }
    for (int i = start; i <= end; ++i) {
        a[i] = temp[i - start];
    }
    temp.clear();
    return result;
}

struct res sort_count_inversion(std::vector<int>& a, int start, int end) {
    if (end - start < 1) {
        struct res result = { a, 0 };
        return result;
    } else {
        int center = (end - start) / 2 + start;
        struct res l = sort_count_inversion(a, start, center);
        struct res r = sort_count_inversion(a, center + 1, end);
        struct res s = count_split(a, start, center, end);
        s.inversions += l.inversions;
        s.inversions += r.inversions;
        return s;
    }
} 


int main() {
    int t = 0;
    int n = 0;
    std::cin >> t;
    std::vector<int> vec;
    for (int i = 0; i < t; ++i) {
        std::cin >> n;
        for (int j = 0; j < n; ++j) {
            int x = 0;
            std::cin >> x;
            vec.push_back(x);
        }
        struct res res = sort_count_inversion(vec, 0, n - 1);
        for (const auto& it : res.a) {
            std::cout << " " << it;
        } 
        std::cout << '\n';
        std::cout << res.inversions << std::endl;
    }
    vec.clear();
}