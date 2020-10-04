/** Nicola Dardanis
 * 
 * Competitive Programming and Contest, a.a. 2020-2021
 * */

/**
 * http://codeforces.com/problemset/problem/579/B?locale=en
 * 
 * There is a programing contest named SnakeUp, 2n people want to compete for it. 
 * In order to attend this contest, people need to form teams of exactly two people. 
 * You are given the strength of each possible combination of two people. All the values of the strengths are distinct.
 * Every contestant hopes that he can find a teammate so that their team’s strength is as high as possible.
 * That is, a contestant will form a team with highest strength possible by choosing a teammate from ones 
 * who are willing to be a teammate with him/her. 
 * More formally, two people A and B may form a team if each of them is the best possible teammate 
 * (among the contestants that remain unpaired) for the other one. Can you determine who will be each person’s teammate?
 * 
 * Input
 * There are 2n lines in the input.
 * The first line contains an integer n (1 ≤ n ≤ 400) — the number of teams to be formed.
 * The i-th line (i > 1) contains i - 1 numbers ai1, ai2, ... , ai(i - 1). 
 * Here aij (1 ≤ aij ≤ 10^6, all aij are distinct) denotes the strength of a team consisting of person i and person j 
 * (people are numbered starting from 1.)
 * 
 * Output
 * Output a line containing 2n numbers. The i-th number should represent the number of teammate of i-th person.
 * 
 * SOLUTION DESCRIPTION:
 * Collect teams description and sort them by strength. Assign pairs greedly.
 * 
 * Complexity: O(n*log(n)) where n is the number of possible teams (rougly n^2).
 * */

#include<iostream>
#include<vector>
#include<algorithm>

struct team {
    size_t mem1;
    size_t mem2;
    int64_t strength;

    team(size_t mem1, size_t mem2, int64_t strength) 
        : mem1(mem1)
        , mem2(mem2)
        , strength(strength) {}
};

int main() {
    size_t N = 0;
    std::cin >> N;
    std::vector<team> teams;
    teams.reserve(N * (N - 1) / 2);
    for (size_t i = 0; i < N * 2; ++i) {
        for (size_t j = 0; j < i; ++j) {
            int32_t x = 0;
            std::cin >> x;
            teams.emplace_back(i, j, x);
        }
    }

    sort(teams.begin(), 
        teams.end(),
        [](const team &a, const team &b) {
            return a.strength > b.strength;
        });

    std::vector<size_t> assign(2*N);
    for (auto &team : teams) {
        if (assign[team.mem1] == 0 && assign[team.mem2] == 0) {
            assign[team.mem1] = team.mem2 + 1;
            assign[team.mem2] = team.mem1 + 1;
        }
    }

    for (auto assignement: assign) {
        std::cout << assignement << " ";
    }
    std::cout << std::endl;;

    assign.clear();
    teams.clear();
    return 0;
}

