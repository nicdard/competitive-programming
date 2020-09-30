/** Nicola Dardanis
 * 
 * Competitive Programming and Contest, a.a. 2020-2021
 * */

/**
 * https://practice.geeksforgeeks.org/problems/next-larger-element/0
 * 
 * Given an array A of size N having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array. If no such element exists, output -1 
 * 
 * Input:
 * The first line of input contains a single integer T denoting the number of test cases.
 * Then T test cases follow. Each test case consists of two lines. 
 * The first line contains an integer N denoting the size of the array. 
 * The Second line of each test case contains N space separated positive integers denoting the values/elements in the array A.
 * 
 * Output:
 * For each test case, print in a new line, the next greater element for each array element separated by space in order.
 * 
 * Constraints:
 * 1 <= T <= 100
 * 1 <= N <= 10^7
 * 1 <= Ai <= 10^18
 * 
 * SOUTION DESCRIPTION:
 * We use a stack as support data structure.
 * We scan the array right to left. We compare each element with the head of the stack, 
 * if it is greater we start pop elements from the stack until a greater one is found and
 * finally we push the current element on top of the stack. For each stack element that we 
 * popped-out we set the new head as its next greater element.
 * At the end, the stack will contain only those elements that were right leaders of the
 * original array. We will set -1 for each of those elements, beacuse it follows from
 * the definition of a right leader that it has not any next greater element in the array.
 * Note that the stack will be always sorted.
 * 
 * Complexity: O(n) both time and space.
 * Note that each element is taken into account by the algorithm not more than 2 times.  
 */

#include<iostream>
#include<vector>
#include<stack>

/**
 * The caller has to deallocate the returned vector.
 */ 
template<typename T>
std::vector<T> next_larger_element(std::vector<T> const& vec) {
    std::vector<T> next_largers;
    std::stack<int> indexes;
    next_largers.reserve(vec.size());
    for (int i = 0; i < vec.size(); ++i) {
        // Initialise here with -1 so we don't have to loop over the remaining elements in the stack at the end.
        next_largers.push_back(-1);
    }
    for (int i = 0; i < vec.size(); ++i) {
        while (!indexes.empty() and vec[indexes.top()] < vec[i]) {
            int vi = indexes.top();
            next_largers[vi] = vec[i];
            indexes.pop();
        }
        indexes.push(i);
    }
    return next_largers;
}

int main() {
    int T, N;
    std::vector<long long> vec;
    std::cin >> T;
    for ( ; T > 0; --T) {
        std::cin >> N;
        vec.reserve(N);
        for ( ; N > 0; --N) {
            int x = 0;
            std::cin >> x;
            vec.push_back(x);
        }
        auto res = next_larger_element(vec);
        for (auto const& l : res) {
            std::cout << l << " ";
        }
        std::cout << std::endl;
        res.clear();
        vec.clear();
    }
    return 0;
}

