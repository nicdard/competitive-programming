#include<iostream>
#include<vector>
#include<cassert>

template<typename Iterator>
int trapped_water(Iterator it, int& level) {
    if (*it > level) {
        level = *it;
    }
    int trapped_water = level - *it;
    assert(trapped_water >= 0);
    return trapped_water;
}

long long trapped_rain_water(std::vector<int> const& vec) {
    long long total = 0;
    int level = 0;
    auto begin = vec.begin();
    auto end = vec.end() - 1;
    while (begin != end) {
        if (*begin <= *end) {
            total += trapped_water(begin, level);
            ++begin;
        } else {
            total += trapped_water(end, level);
            --end;
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
        long long total = trapped_rain_water(vec);
        std::cout << total << std::endl;
        vec.clear(); 
    }
    return 0;
}