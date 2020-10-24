假设一个符合条件的二元组是 $(a, b)$，那么我们可以得到

$$ (a-1) * d + b \equiv (b-1)*d + a \pmod w$$

$$ (a-b)*(d-1) \equiv 0 \pmod w $$

设 $ x = gcd( d-1, w) $, 我们有 $(a-b) * (d-1) / x \equiv 0 \pmod {w/x}$

因为 $ a \lt b,$ 所以 $ (b-a) *(d-1)/x \% (w/x) = 0$ 

然后我们考虑 $a, b$ 的取值范围，可以发现 $1 \leq a, b \leq min(m, d) $

不妨设 $c = b-a$ , 我们有 $c \in [1, min(m, d)-1] $

上式可转换为 $c * (d-1) / x \% (w/x) = 0$。

又因为 $gcd(d-1, w) = x,$ 所以 $ gcd(\frac{d-1}{x}, \frac{w}{x} = 1)$

所以 $ c \\% (w/x) = 0$

所以 $ answer = \sum_{c=1}^{min(m,d) - 1} (min(m, d) - c) * [c\\%\frac{w}{x}==0]$

设$upper = min(m, d) - 1, d = \frac{w}{x}$ 的倍数( $d = 1$ 表示此时 $c = \frac{w}{x}$)，我们有

$answer = \sum_{d = 1}^{upper/{\frac{w}{x}}} (upper+1 - d*\frac{w}{x})$
