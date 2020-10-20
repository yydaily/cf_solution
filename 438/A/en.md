## <p align="center">A. The Child and Toy</p>

<p align="center"> time limit per test: 1 seconds</p>
<p align="center"> memory limit per test 256 megabytes</p>
<p align="center"> input: standard input</p>
<p align="center"> output: standard output</p>

On Children's Day, the child got a toy from Delayyy as a present. However, the child is so naughty that he can't wait to destroy the toy.

The toy consists of $n$ parts and $m$ ropes. Each rope links two parts, but every pair of parts is linked by at most one rope. To split the toy, the child must remove all its parts. The child can remove a single part at a time, and each remove consume an energy. Let's define an energy value of part $i$ as $v_i$. The child spend $v_{f_1}$ + $v_{f_2}$ + ... + $v_{f_k}$ energy for removing part $i$ where $f_1$, $f_2$, ..., $f_k$ are the parts that are directly connected to the $i$-th and haven't been removed.

Help the child to find out, what is the minimum total energy he should spend to remove all $n$ parts.

### Input

The first line contains two integers n and m ($1 \leq n \leq 1000; 0 \leq m \leq 2000$). The second line contains $n$ integers: $v_1, v_2, \dots, v_n$ ($0 \leq v_i \leq 10^5$). Then followed $m$ lines, each line contains two integers $x_i$ and $y_i$, representing a rope from part $x_i$ to part $y_i$ ($1 \leq x_i, y_i \leq n; x_i \neq y_i$).

Consider all the parts are numbered from $1$ to $n$.

### Output

Output the minimum total energy the child should spend to remove all $n$ parts of the toy.

### Examples
|input|
|:------|
|4 3<br>10 20 30 40<br>1 4<br>1 2<br>2 3|
|**output**|
|40|

|input|
|:------|
|4 4<br>100 100 100 100<br>1 2<br>2 3<br>2 4<br>3 4|
|**output**|
|400|

|input|
|:------|
|7 10<br>40 10 20 10 20 80 40<br>1 5<br>4 7<br>4 5<br>5 2<br>5 7<br>6 4<br>1 6<br>1 3<br>4 3<br>1 4|
|**output**|
|160|

### Note

One of the optimal sequence of actions in the first sample is:

First, remove part $3$, cost of the action is $20$.

Then, remove part $2$, cost of the action is $10$.

Next, remove part $4$, cost of the action is $10$.

At last, remove part $1$, cost of the action is $0$.

So the total energy the child paid is $20 + 10 + 10 + 0 = 40$, which is the minimum.

In the second sample, the child will spend $400$ no matter in what order he will remove the parts.


