<center>B. Polycarp's Practice</center>
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarp is practicing his problem solving skill. He has a list of 𝑛 problems with difficulties 𝑎1,𝑎2,…,𝑎𝑛, respectively. His plan is to practice for exactly 𝑘 days. Each day he has to solve at least one problem from his list. Polycarp solves the problems in the order they are given in his list, he cannot skip any problem from his list. He has to solve all 𝑛 problems in exactly 𝑘 days.

Thus, each day Polycarp solves a contiguous sequence of (consecutive) problems from the start of the list. He can't skip problems or solve them multiple times. As a result, in 𝑘 days he will solve all the 𝑛 problems.

The profit of the 𝑗-th day of Polycarp's practice is the maximum among all the difficulties of problems Polycarp solves during the 𝑗-th day (i.e. if he solves problems with indices from 𝑙 to 𝑟 during a day, then the profit of the day is max𝑙≤𝑖≤𝑟𝑎𝑖). The total profit of his practice is the sum of the profits over all 𝑘 days of his practice.

You want to help Polycarp to get the maximum possible total profit over all valid ways to solve problems. Your task is to distribute all 𝑛 problems between 𝑘 days satisfying the conditions above in such a way, that the total profit is maximum.

For example, if 𝑛=8,𝑘=3 and 𝑎=[5,4,2,6,5,1,9,2], one of the possible distributions with maximum total profit is: [5,4,2],[6,5],[1,9,2]. Here the total profit equals 5+6+9=20.

Input
The first line of the input contains two integers 𝑛 and 𝑘 (1≤𝑘≤𝑛≤2000) — the number of problems and the number of days, respectively.

The second line of the input contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤2000) — difficulties of problems in Polycarp's list, in the order they are placed in the list (i.e. in the order Polycarp will solve them).

Output
In the first line of the output print the maximum possible total profit.

In the second line print exactly 𝑘 positive integers 𝑡1,𝑡2,…,𝑡𝑘 (𝑡1+𝑡2+⋯+𝑡𝑘 must equal 𝑛), where 𝑡𝑗 means the number of problems Polycarp will solve during the 𝑗-th day in order to achieve the maximum possible total profit of his practice.

If there are many possible answers, you may print any of them.
