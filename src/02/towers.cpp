/** Nicola Dardanis
 * 
 * Competitive Programming and Contest, a.a. 2020-2021
 * */

/**
 * http://codeforces.com/problemset/problem/37/A?locale=en
 * 
 * Little Vasya has received a young builder’s kit. The kit consists of several wooden bars,
 * the lengths of all of them are known. The bars can be put one on the top of the other if their lengths are the same.
 * Vasya wants to construct the minimal number of towers from the bars. Help Vasya to use the bars in the best way possible.
 * 
 * Input
 * The first line contains an integer N (1 ≤ N ≤ 1000) — the number of bars at Vasya’s disposal.
 * The second line contains N space-separated integers li — the lengths of the bars.
 * All the lengths are natural numbers not exceeding 1000.
 * 
 * Output
 * In one line output two numbers — the height of the largest tower and their total number. 
 * Remember that Vasya should use all the bars.
 * 
 * SOLUTION DESCRIPTION
 * We use a map with keys the different lengths of the bars and values the number of them by value.
 * We compute the maximum while adding the elements to the map to avoid a late search for the maximum.
 * 
 * Complexity: O(n).
 */

#include<iostream>
#include<map>

int main() {
    int N;
    std::map<int, int> bars_by_length;
    std::cin >> N;
    int max = 0;
    for (; N > 0; --N) {
        int l = 0;
        std::cin >> l;
        bars_by_length[l] += 1;
        if (bars_by_length[l] > max) {
            max = bars_by_length[l];
        }
    }
    int towers = bars_by_length.size();
    std::cout << max << " " << towers << std::endl;;
    return 0;
}