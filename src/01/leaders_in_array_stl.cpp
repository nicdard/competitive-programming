/**
 * The solution for the exercise Leaders in Array using the standard template library.
 */
#include <iostream>
#include <vector>

using namespace std;

void print_leaders(vector<int> const& vec) {
    vector<int> leaders;
    leaders.reserve(vec.size());
    int max = vec.back();
    leaders.push_back(max);
    for (auto it = vec.rbegin() + 1; it != vec.rend(); ++it) {
        if (*it > max) {
            max = *it;
            leaders.push_back(max);
        }
    }

    for (auto it = leaders.rbegin(); it != leaders.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    int T = 0;
    cin >> T;
    vector<int> v;
    for (int i = 0; i < T; i++) {
        int n = 0;
        cin >> n;
        v.reserve(n);
        for (int j = 0; j < n; j++) {
            int x = 0;
            cin >> x;
            v.push_back(x);
        }
        print_leaders(v);
        v.clear();
    }
    return 0;
}
