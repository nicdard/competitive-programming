/** Nicola Dardanis
 * 
 * Competitive Programming and Contest, a.a. 2020-2021
 * */


/*
 * Given an array of positive integers. Your task is to find the leaders in the array.
 * Note: An element of array is leader if it is greater than or equal to all the elements to its right side. Also, the rightmost element is always a leader. 
 * 
 * Input:
 * The first line of input contains an integer T denoting the number of test cases. 
 * The description of T test cases follows.
 * The first line of each test case contains a single integer N denoting the size of array.
 * The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.
 * 
 * Output:
 * Print all leaders.
 * 
 * Constraints:
 * 1 <= T <= 100
 * 1 <= N <= 10^7
 * 0 <= Ai <= 10^7
 * 
 * SOLUTION DESCRIPTION:
 * We store all the values in an array and then we scan it backwards for leaders:
 * - We keep the local maximum of the visited portion of the array in a temp variable (max) initialised with -1.
 * - Every time we find a number greater than max we print it and we update max.
 * 
 * Compexity: O(n) both for space and time.
 */

#include<bits/stdc++.h>

using namespace std;

#define MAX 10000000

long long V[MAX + 1];

int main(void) {
    int T, N;
    int max = -1;
    cin >> T;
    while ( T-- ) {
        cin >> N;
        int i;
        for (i = 0; i < N; i++) {
            cin >> V[i];
        }
        for (i = N - 1; i >= 0; i--) {
            if (V[i] > max) {
                max = V[i];
            } else {
                V[i] = -1;
            }
        }
        for (i=0; i < N; i++) {
            if (V[i] > -1) {
                cout << V[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}