## <center>D. Devu 和他的兄弟</center>

<center> 时间限制: 1 秒</center>
<center> 空间限制: 256 M</center>
<center> 输入: 标准输入</center>
<center> 输出: 标准输出</center>

Devu和他的兄弟彼此相爱。因为他们是超级极客，所以他们只喜欢玩数组。他们的父亲给了他们两个数组 $a$ 和 $b$ 。数组 $a$ 给Devu，数组 $b$ 给他的兄弟。

由于Devu确实是个顽皮的孩子，他希望数组 $a$ 的最小值至少应等于其兄弟数组 $b$ 的最大值。

现在，您必须帮助Devu实现此条件。您可以对阵列执行多项操作。在单个操作中，允许将任何数组的任何元素减少或增加 $1$ 。请注意，允许对数组的任何索引多次应用该操作。

您需要找到满足Devu的条件所需的最少操作数，以便兄弟俩可以在不打架的情况下和平进行游戏。

### 输入

第一行包含两个空格分开的整数 $n, m$ ($1 \leq n, m \leq 10^5$)。第二行包含 $n$ 个空格分开的整数数组 $a$ ($1 \leq a_i \leq 10^9)，第三行包含 $m$ 个空格分开的整数数组 $b$ ($1 \leq b_i \leq 10^9$)。

### 输出

您需要输出一个整数，该整数表示满足Devu条件所需的最少操作数。

### 样例

|输入|
|:------|
|2 2<br>2 3<br>3 5|
|**输出**|
|3|

|输入|
|:------|
|3 2<br>1 2 3<br>3 4|
|**输出**|
|4|

|输入|
|:------|
|3 2<br>4 5 6<br>1 2|
|**输出**|
|0|

### 注意

在样例 1，可以把 $a_1$ 加一，$b_2$ 减一两次。现在数组 $a$ 将为$[ 3 ; 3 ]$并且数组 $b$ 也将是 $[ 3 ; 3 ]$ 。因此，满足Devu的条件所需的最少操作数为 $3$ 。

在示例3中，您不需要执行任何操作，因为Devu的条件已经满足。
