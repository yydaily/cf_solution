## <p align="center">E. Merge Equal Elements</p>

<p align="center"> 时间限制：1秒</p>
<p align="center"> 空间限制：256M</p>
<p align="center"> 输入：标准输入</p>
<p align="center"> 输出：标准输出</p>

输入一个长度为 $n$ 的数组 $a_1, a_2, \dots, a_n$.

如果可以，你将进行下述操作：找到两个相同的连续的数字。如果有超过一对，选择最左侧的（也即最小下标的）。如果两个数字的值是 $x$，删除这两个数字，并在原来的位置上插入 $x+1$ 。用这种方式，数组长度每次都会减一。

重复上述步骤，直到找不到两个连续相同的数字。

举个栗子，如果初始的数组为 $[5, 2, 1, 1, 2, 2]$，第一次操作，会变成，$[5, 2, 2, 2, 2]$，然后会变成 $[5, 3, 2, 2]$，然后就是 $[5, 3, 3]$，最终得到 $[5, 4]$。然后没有相同的数字了，你停止了这个操作。

输出处理完成后的数组。

### 输入

第一行包含一个数字 $n$ ($2 \leq n \leq 2·10^5$) - 表示数组长度。

第二行为一个长度为 $n$ 的数组 $a_1, a_2, \dots, a_n$ ($1 \leq a_i \leq 10^9$).

### 输出

第一行输出一个数字 $k$ - 表示最终处理完后的数组长度。

第二行输出 $k$ 个数字，表示处理完后的数组。

### 样例

|input|
|:------|
|6<br>5 2 1 1 2 2|
|**output**|
|2<br>5 4|

|input|
|:------|
|4<br>1000000000 1000000000 1000000000 1000000000|
|**output**|
|1<br>1000000002|

|input|
|:------|
|7<br>4 10 22 11 12 5 6|
|**output**|
|7<br>4 10 22 11 12 5 6|

### 提示

第一个样例的解释在题面描述中了。

第二个样例的初始数组是 $[1000000000, 1000000000, 1000000000, 1000000000]$. 第一次操作后变成 $[1000000001, 1000000000, 1000000000]$. 第二次操作后变成 $[1000000001, 1000000001]$. 第三次操作后变成 $[1000000002]$.

第三个样例因为没有相同的可以合并的数字，所以没有任何变化。
