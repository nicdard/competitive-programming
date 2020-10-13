/** Nicola Dardanis
 * 
 * Competitive Programming and Contest, a.a. 2020-2021
 * */

/**
 * The Interpolation Search is an improvement over Binary Search for instances, 
 * where the values in a sorted array are uniformly distributed. 
 * 
 * Binary Search always goes to the middle element to check. 
 * On the other hand, interpolation search may go to different locations according 
 * to the value of the key being searched.
 * For example, if the value of the key is closer to the last element, interpolation
 * search is likely to start search toward the end side.
 * 
 * The position to be searched is calculated according to:
 * pos = start + [ (x-arr[start])*(end-start) / (arr[start]-arr[end]) ]
 * arr[]    ==> Array where elements need to be searched
 * x        ==> Element to be searched
 * start    ==> Starting index in arr[]
 * end      ==> Ending index in arr[]
 * 
 * Step1: In a loop, calculate the value of “pos” using the probe position formula.
 * Step2: If it is a match, return the index of the item, and exit.
 * Step3: If the item is less than arr[pos], calculate the probe position of the left sub-array. Otherwise calculate the same in the right sub-array.
 * Step4: Repeat until a match is found or the sub-array reduces to zero.
 * 
 * Time Complexity: If elements are uniformly distributed, then O (log log n)). 
 * In worst case it can take upto O(n).
 * Auxiliary Space: O(1)
 */
#include <iostream>
#include <vector>

template <typename T>
int interpolation_search(std::vector<T> const& vec, T k, int start, int end) {
    if (start <= end && k >= vec[start] && k <= vec[end]) {
        int pos = start + (((double)(end - start) / (vec[end] - vec[start])) * (k - vec[start]));
        if (vec[pos] == k) {
            return pos;
        } 
        if (vec[pos] > k) {
            // Go to the left subarray.
            return interpolation_search(vec, k, start, pos - 1);
        } 

        if (vec[pos] < k) {
            // Search the right subarray.
            return interpolation_search(vec, k, pos + 1, end);
        }
    
    }
    return -1;
}

int main() {
    int N = 0, k = 0;
    std::vector<int> vec;
    std::cin >> N;
    std::cin >> k;
    vec.reserve(N);
    for (int i = 0; i < N; ++i) {
        int x = 0;
        std::cin >> x;
        vec.push_back(x);
    }
    int pos = interpolation_search(vec, k, 0, N - 1);
    std::cout << pos << std::endl;
    vec.clear();
    return 0;
}