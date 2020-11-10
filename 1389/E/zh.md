## <center>E. 日历歧义</center>

<center> 时间限制：2秒</center>
<center> 空间限制：256M</center>
<center> 输入：标准输入</center>
<center> 输出：标准输出</center>


Berland 年包括 $m$ 个月，每个月 $d$ 天。 月份从 $1$ 到 $m$ 编号。 Berland 一周包含 $w$ 天。这一年第一个月的第一天也是一周的第一天。注意：这一年的最后一周可能没有 $w$ 天。

一个二元组 ($x, y$) 满足 $x \lt y$ 第 $y$ 月的第 $x$ 天 和 第 $x$ 月的第 $y$ 天是一周的同一天，被认为是有歧义的。

计算有多少个这样有歧义的二元组。

### 输入

第一行包含一个整数 $t$ ($1 \leq t \leq 1000$) - 表示测试用例的数量。

接下来 $t$ 行，每一行包含三个整数 $m, d$ 和 $w$ ($1 \leq m, d, w \leq 10^9$) - 分别表示一年有多少个月，一个月有多少天，一周有多少天。

### 输出

输出 $t$ 个整数 - 表示每个测试用例对应的有歧义的满足 $x \lt y$ 二元组 $(x, y)$数量。

### 样例

|输入|
|:------|
|5<br>6 7 4<br>10 7 12<br>12 30 7<br>1 1 1<br>3247834 10298779 625324|
|**输出**|
|6<br>9<br>5<br>0<br>116461800|

### 说明

这是第一个样例的日历及其二元组展示：

![](https://github.com/yydaily/cf_solution/blob/master/1389/E/cf_1389_E.png?raw=true)
