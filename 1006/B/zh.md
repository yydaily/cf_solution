## <p align="center">B. Polycarp的练习题</p>

<p align="center"> 时间限制: 2 秒</p>
<p align="center"> 空间限制: 256 M</p>
<p align="center"> 输入: 标准输入</p>
<p align="center"> 输出: 标准输出</p>

Polycarp 在锻炼他的解题技巧.他有难度分别为$a_1, a_2, \dots, a_n$的 $n$ 个题目。 他有 $n$ 个难度分别为 $a_1, a_2, \dots a_n$ 的题目。他想刚好在 $k$ 天做完。每天他都要从上面的列表中至少完成 $1$ 题。Polycarp 要按照给出的题目顺序解题，并且不能跳过题目。他需要刚好在 $k$ 天完成 $n$ 道题目。

因此，每天Polycarp需要解决问题列表中连续的一段问题。他不能跳过任何问题或者解决一个问题多次。最后，他需要在在 $k$ 天内解决所有的 $n$ 个问题。

Polycarp第 $j$ 天的收益是他在这天解决的所有问题的最大难度，（例如，他在这天解决了第 $i$ 到第 $j$ 个问题，那么这天的收益就是 $max_{l\leq i\leq r} a_i$）。总收益就是这 $k$ 天练习的收益之和。

你想帮助Polycarp在所有可行方式中获得最大收益。你的任务就是找到一种 $k$ 天这 $k$ 个问题的方式，以期获得最大收益。

例如，如果 $n=3$，$k=8$ 并且 $a=[5,4,2,6,5,1,9,2]$，其中一种方式就是按照 $[5,4,2],[6,5],[1,9,2]$ 的方式刷题。那么总收益是 $5+6+9=20$ 。

### 输入

第一行输入包含两个整数 $n$ 和 $k$ ($1\leq k\leq n\leq 2000$) - 代表题目数量和所需天数。

第二行包含 $n$ 个整数 $a_1, a_2, \dots, a_n(1\leq a_i\leq 2000)$ - 代表Polycarp的题目列表，和题目的顺序（意思是，他会按照顺序解决这些问题）。

### 输出

第一行输出他的总收益。

第二行会有正好 $k$ 个正整数 $t_1, t_2, \dots, t_k (t_1 + t_2 + \dots + t_k)$ 必须等于 $n$，其中 $t_j$ 表示Polycarp按照他的习题列表顺序做题获得最大收益时，第 $j$ 天的收益。

如果有多种可能达到相同的收益，你可以输出任意一种。

### 样例

|input|
|:------|
|8 3<br>5 4 2 6 5 1 9 2|
|**output**|
|20<br>3 2 3|

|input|
|:------|
|5 1<br>1 1 1 1 1|
|**output**|
|1<br>5|

|input|
|:------|
|4 2<br>1 2000 2000 2|
|**output**|
|4000<br>2 2|



