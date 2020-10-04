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
 */

#include<stdlib.h>

struct res {
    int[] a;
    int inversions;
}

struct res sort_count_inversion(int *a, int start, int end);
struct res count_split(int *a, int start, int end);

struct res sort_count_inversion(int *a, int start, int end) {
    if (end - start <= 1) {
        return 0;
    } else {
        int center = (end - start) / 2 + start;
        struct res l = sort_count_inversion(a, start, center);
        struct res r = sort_count_inversion(a, center + 1, end);
        struct res s = count_split(a, start, end);
        return l + r + s;
    }
} 


int main() {
    int t = 0;
    int n = 0;

}