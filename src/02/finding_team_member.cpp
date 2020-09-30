

/**
 * There is a programing contest named SnakeUp, 2n people want to compete for it. 
 * In order to attend this contest, people need to form teams of exactly two people. 
 * You are given the strength of each possible combination of two people. All the values of the strengths are distinct.
 * Every contestant hopes that he can find a teammate so that their team’s strength is as high as possible.
 * That is, a contestant will form a team with highest strength possible by choosing a teammate from ones 
 * who are willing to be a teammate with him/her. More formally, two people A and B may form a team if each
 * of them is the best possible teammate (among the contestants that remain unpaired) for the other one.
 * Can you determine who will be each person’s teammate?
 * 
 * Input
 * There are 2n lines in the input.
 * The first line contains an integer n (1 ≤ n ≤ 400) — the number of teams to be formed.
 * The i-th line (i > 1) contains i - 1 numbers ai1, ai2, ... , ai(i - 1). 
 * Here aij (1 ≤ aij ≤ 106, all aij are distinct) denotes the strength of a team consisting of person i and person j 
 * (people are numbered starting from 1.)
 * 
 * Output
 * Output a line containing 2n numbers. The i-th number should represent the number of teammate of i-th person.
 */