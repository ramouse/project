```txt
Problem A. Sixteen
Input file: standard input
Output file: standard output
```

给定一个整数x。你的任务是构造一个方形整数矩阵，使其行列式恰好等于x。

更正式地，对于每个给定的整数x，你需要输出一个整数n 和一个n×n 矩阵A，满足：

$1 \leq n \leq 1 6 ;$

• A 中的每个元素都是介于−16 和16 之间的整数（包括16和−16）；

• det(A) = x。

如果有多个合法答案，你可以输出其中任意一个。

## Input

第一行包含一个整数T $( 1 \leq T \leq 1 0 0 )$ — 测试用例的数量。

接下来的T 行中，每行包含一个整数x $( - 2 ^ { 7 5 } < x < 2 ^ { 7 5 } )$

## Output

对于每个测试用例，按如下格式输出一个合法构造。

首先输出一个整数 $n \ ( 1 \leq n \leq 1 6 )$ — 矩阵的大小。

然后输出n 行。第i 行应包含n 个整数 $a _ { i , 1 } , a _ { i , 2 } , \dotsc , a _ { i , n } \ ( - 1 6 \leq a _ { i , j } \leq 1 6 )$ — 矩阵的元素。

所打印矩阵的行列式必须等于对应的整数x。

如果有多个合法答案，你可以输出其中任意一个。

## Example

<table><tr><td>standard input</td><td>standard output</td></tr><tr><td>5</td><td>1</td></tr><tr><td>1</td><td>1</td></tr><tr><td>2</td><td>2</td></tr><tr><td>22</td><td>0 1</td></tr><tr><td>-32</td><td>-2 3</td></tr><tr><td>138</td><td>2</td></tr><tr><td></td><td>7 5</td></tr><tr><td></td><td>-3 1</td></tr><tr><td></td><td>3</td></tr><tr><td></td><td>-1 0 2</td></tr><tr><td></td><td>3 4 -2</td></tr><tr><td></td><td>1 1 7</td></tr><tr><td></td><td>3</td></tr><tr><td></td><td>-2 12 -1</td></tr><tr><td></td><td>-1 3 4</td></tr><tr><td></td><td>1 7 4</td></tr></table>

<div class="mineru-algorithm" style="white-space: pre-wrap; font-family:monospace;">
- $1 \leq x_{1} &lt; q$, $1 \leq x_{2} &lt; p$;
- $x_{1}^{2} \equiv p \pmod{q}$;
- $x_{2}^{2} \equiv q \pmod{p}$。
</div>

```txt
Problem B. Quadratic Residue
Input file: standard input
Output file: standard output
```

给定一个正整数p，你的任务是找到三个正整数x 、x 和q，使得：

这里， $a \equiv b { \pmod { c } }$ 表示a 除以c 的余数与b 除以c 的余数相同。

如果存在多个解，输出任意一组合法的整数 $( x _ { 1 } , x _ { 2 } , q )$ 即可。如果不存在这样的整数，则报告无法做到。Input

第一行包含一个整数T $\left( 1 \le T \le 1 0 ^ { 4 } \right)$ ，表示测试用例的数量。

接下来的T 行中，每行包含一个整数 ${ \mathrm { ~ \it ~  ~ } } [ 2 { \mathrm { ~  ~ { \left( 2 \leq p \leq 1 0 ^ { 9 } \right) } } }$

## Output

对于每个测试用例，输出一行：

如果存在解，输出三个整数 $x _ { 1 } \cdot x _ { 2 }$ 和q $( 1 \leq q \leq 1 0 ^ { 1 2 } , ~ 1 \leq x _ { 1 } < q , ~ 1 \leq x _ { 2 } < p )$ ，用空格分隔。如果不存在解，输出单词<sub>Impossible</sub>。

## Example

<table><tr><td>standard input</td><td>standard output</td></tr><tr><td>3</td><td>12 1 71</td></tr><tr><td>2</td><td>19 2 89</td></tr><tr><td>5</td><td>12 3 69</td></tr><tr><td>6</td><td></td></tr></table>

## Problem C. 重测队列

Input file: standard input

Output file: standard output

一次大型比赛结束后，评测集群还要做一次复查：把n 个程序在同一套m 个测试点上重新评测。每个程序都会使用同一个测试点队列。

评测机处理一个程序时，会从队列开头依次运行测试点。一旦某个测试点给出拒绝结果，评测机在运行完这个测试点后立刻停止处理这个程序。通过全部测试点的程序会运行完整个队列。

复查开始前，历史日志已经给出了每个程序在每个测试点上的表现。第i 个程序运行第j 个测试点需要 $\cdot d _ { i , j }$ 的时间，结果要么是接受，要么是拒绝。无论结果如何，只要这个测试点被实际运行， $d _ { i , j }$ 都会计入集群总耗时。

你可以在复查前任意重排这m 个测试点。求评测完全部n 个程序所需的最小总耗时。

## Input

第一行包含两个整数n 和m，分别表示程序个数和测试点个数。

接下来 $\boldsymbol { n }$ 行，第i 行描述第i 个程序。每行先包含m 个整数 ${ \bf \ddot { } } d _ { i , 1 } , d _ { i , 2 } , \ldots , d _ { i , m }$ ，随后包含一个长度为m 的字符串 $s _ { i }$ 。若 $s _ { i }$ 的第j 个字符为<sub>A</sub>，表示第i 个程序在第j 个测试点上的结果是接受；若为<sub>R</sub>，表示结果是拒绝。

保证1 $\stackrel { \triangledown } { { \le } } { \bf { \Phi } } n \le 2 \times 1 0 ^ { 4 } , 1 \le m \le 2 0 , 1 \le d _ { i , j } \le 1 0 ^ { 9 }$ ，且 $s _ { i }$ 仅包含字符<sub>A</sub> 和<sub>R</sub>。

## Output

输出一个整数，表示最小可能的总耗时。

Example

<table><tr><td>standard input</td><td>standard output</td></tr><tr><td>3 3</td><td>27</td></tr><tr><td>3 10 2 ARA</td><td></td></tr><tr><td>5 1 4 RAA</td><td></td></tr><tr><td>2 2 7 AAR</td><td></td></tr></table>

## Note

一种最优顺序是先运行第2 个测试点，再运行第1 个测试点，最后运行第3 个测试点。在这个顺序下，三个程序的耗时分别为 $1 0 \cdot 1 + 5 = 6 \cdot 2 + 2 + 7 = 1 1$ ，总耗时为27。

## Problem D. The Game

Input file: standard input

Output file: standard output

Alice 和Bob 正在玩一个游戏。

初始时，有一个空序列。他们会得到一个整数n，并共同构造一个长度为n 的排列p。

Alice 先手。每一步中，当前玩家需要从1 到n 中选择一个此前尚未被选择过的整数，并将其添加到序列末尾。恰好进行n 步后，该序列将成为1,2,...,n 的一个排列p。

对于排列 $\left| p \right. = \left( p _ { 1 } , p _ { 2 } , \ldots , p _ { n } \right)$ ，它的一个循环移位是指：选择一个下标i $( 1 ~ \leq ~ i ~ \leq ~ n )$ ，并得到序列 $\left| ( p _ { i } , p _ { i + 1 } , \ldots , p _ { n } , p _ { 1 } , p _ { 2 } , \ldots , p _ { i - 1 } ) \right.$

例如，排列(2, 3, 1) 的所有循环移位为(2, 3, 1)、(3, 1, 2) 和(1, 2, 3)。

对于一个排列p，定义f(p) 为p 的所有循环移位中字典序最小的一个。

Alice 希望让f(p) 的字典序尽可能小，而Bob 希望让它的字典序尽可能大。

假设双方都采取最优策略，请求出最终得到的排列f(p)。

## Input

第一行包含一个整数 $T \ : \ : \left( 1 \leq T \leq 1 0 ^ { 5 } \right)$ ，表示测试用例的数量。

接下来T 行，每行包含一个整数n $\left( 1 \leq n \leq 5 \cdot 1 0 ^ { 5 } \right)$ C

保证所有测试用例中n 的总和不超过5·10<sup>5</sup>。

## Output

对于每个测试用例，输出n 个整数，表示双方均采取最优策略时最终得到的排列f(p)。

## Example

<table><tr><td>standard input</td><td>standard output</td></tr><tr><td>4</td><td>1</td></tr><tr><td>1</td><td>1 2</td></tr><tr><td>2</td><td>1 3 2</td></tr><tr><td>3</td><td>1 3 2 4</td></tr><tr><td>4</td><td></td></tr></table>

```txt
Problem E. DPRS
Input file: standard input
Output file: standard output
```

给定一个强连通的带权有向图，图中有n 个顶点和m 条有向边。顶点编号从1 到n，边编号从1 到m。第k 条边记为 $( u _ { k } , v _ { k } , w _ { k } )$ ，表示存在一条从 $\mathbf { \nabla } _ { \boldsymbol { u } _ { k } }$ 到 $v _ { k }$ 的有向边，权值为 $w _ { k }$

设 $d i s ( i , j )$ 表示从顶点i 到顶点j 的最短路长度。

对于一个图，定义它的价值为

$$
\max_{\substack{1\leq i,j\leq n\\ i\neq j}}\frac{dis(i,j)}{dis(j,i)}.
$$

有q 个询问。每个询问给出一条边的编号k 和一个新的权值x，其中 $1 \leq x < w _ { k }$ 。对于这个询问，仅在当前询问中，第k 条边的权值临时改为x。你需要输出在这次临时修改后图的价值。

所有询问彼此独立。也就是说，每个询问结束后，图都会恢复为原始状态。

## Input

第一行包含一个整数T $( 1 \leq T \leq 1 0 0 0 )$ ，表示测试用例的数量。

对于每个测试用例，第一行包含三个整数 $\therefore m , q \ ( 2 \leq n \leq m \leq 2 0 0 0 , \ 1 \leq q \leq 2 0 0 0 )$ o

所 有 测 试 用 例 中 ，n 的 总 和 、m 的 总 和 以 及 $. q$ 的 总 和 都 不 超 过2000。 也 就 是说， $\textstyle \sum n \leq 2 0 0 0$ ，P $m \leq 2 0 0 0$ ，且 $\Sigma q \leq 2 0 0 0$

接下来m 行，每行包含三个整数 $u _ { k } , v _ { k } , w _ { k }$ ，描述第k 条有向边，其中 $1 \ \leq \ u _ { k } , v _ { k } \ \leq \ n , \ u _ { k } \ \neq \ v _ { k }$ 且 $1 \leq w _ { k } \leq 1 0 ^ { 9 }$

保证每个测试用例中的图都是强连通的。

接下来q 行，每行包含两个整数k,x，描述一个询问，其中 $1 \leq k \leq m$ 且 $1 \leq x < w _ { k }$ 。

在这个询问中，第k 条边的权值会被临时改为x。

## Output

对于每个询问，输出一行一个实数，表示所有有序点对 $( i , j ) \ \ d j ^ { \mathrm { ~ ~ } } ( i \neq j )$ 中 $\frac { d i s ( i , j ) } { d i s ( j , i ) }$ 的最大值。如果你的答案的绝对误差或相对误差不超过 $1 0 ^ { - 6 }$ ，则会被判定为正确。

Example

<table><tr><td>standard input</td><td>standard output</td></tr><tr><td>2</td><td>6.000000000000</td></tr><tr><td>3 3 2</td><td>7.000000000000</td></tr><tr><td>1 2 2</td><td>6.000000000000</td></tr><tr><td>2 3 3</td><td>3.750000000000</td></tr><tr><td>3 1 4</td><td>3.600000000000</td></tr><tr><td>2 1</td><td>7.500000000000</td></tr><tr><td>1 1</td><td></td></tr><tr><td>5 7 4</td><td></td></tr><tr><td>1 2 7</td><td></td></tr><tr><td>1 4 3</td><td></td></tr><tr><td>2 3 4</td><td></td></tr><tr><td>4 1 2</td><td></td></tr><tr><td>1 5 5</td><td></td></tr><tr><td>5 2 6</td><td></td></tr><tr><td>3 1 8</td><td></td></tr><tr><td>5 3</td><td></td></tr><tr><td>6 5</td><td></td></tr><tr><td>1 4</td><td></td></tr><tr><td>3 2</td><td></td></tr></table>

## Problem F. 23 子序列

Input file: standard input

Output file: standard output

定义一个序列b $\mathbf { \Omega } ^ { \prime } = \left( b _ { 1 } , b _ { 2 } , \ldots , b _ { m } \right)$ 是好的，当且仅当对于每一个 $i = 2 , 3 , \ldots , m$ ，都有

$$
2 \cdot b _ {i - 1} \leq b _ {i} \leq 3 \cdot b _ {i - 1}.
$$

特别地，长度为1 的序列总是好的。

现在给定一个长度为n 的正整数序列 ${ \bf \Pi } _ { a } = ( a _ { 1 } , a _ { 2 } , \ldots , a _ { n } )$ 。你需要回答q 次询问，每次询问给出一个区间 $[ l , r ] ~ \left( 1 \leq l \leq r \leq n \right)$ ，请找出在子序列 $a _ { l } , a _ { l + 1 } , \ldots , a _ { r }$ 中（保持原顺序），最长的好的子序列的长度。

注意：子序列不一定是连续的，但必须保持原序列中的相对顺序。

## Input

第一行两个整数n,q，分别表示序列长度和询问次数。

第二行n 个整数 $\mathbf { \dot { } } a _ { 1 } , a _ { 2 } , \dots , a _ { n }$ C

接下来q 行，每行两个整数l,r，表示一次询问的区间。

Output

输出q 行，每行一个整数，依次为每个询问的答案。

Example

<table><tr><td>standard input</td><td>standard output</td></tr><tr><td>5 4</td><td>3</td></tr><tr><td>1 2 4 6 17</td><td>2</td></tr><tr><td>1 3</td><td>4</td></tr><tr><td>2 4</td><td>3</td></tr><tr><td>1 5</td><td></td></tr><tr><td>1 4</td><td></td></tr></table>

## Note

$1 \leq { n } , { q } \leq 2 \times 1 0 ^ { 5 } , 1 \leq { a } _ { i } \leq 1 0 ^ { 1 8 }$ ，对于每次询问， $1 \leq l \leq r \leq n .$ 0

## Problem G. 消逝的回忆

Input file: standard input Output file: standard output

Please remember that I was once here—and then, slowly, let the memory fade. But look: those words that lingered unspoken, those gestures still suspended in midair, have all remained here, as though they were never truly brought to an end. The wind will still pass through this street, stirring the hem of your clothes, and carrying back some distant fragment of the past— If everything is destined to fade away, could we walk this road once more?

— Anonymous

给定一个长度为n 的序列b。

定义一个区间 $[ l , r ]$ 是好的，当且仅当对于所有l $\leq i \leq r$ ，满足

$$
\min (b _ {l}, b _ {r}) \leq b _ {i} \leq \max (b _ {l}, b _ {r}).
$$

你可以进行任意次如下操作：

选择一个好的区间 $[ l , r ]$ ，然后将下标在l +1 到r −1 之间的元素全部删除。删除后序列长度缩短，原先l与 $\dot { \boldsymbol { { r } } }$ 变为相邻元素，后续的操作都在新的序列上进行。

你的目标是通过最优的操作顺序，使最终序列的长度尽可能小。这个最小值被称为该序列的消除后长度。

现在你需要处理 $\{ q$ 个事件，每个事件是以下两种之一：

$_ \mathrm { ~ 1 ~ } x \mathrm { ~ y ~ }$ —— 将 $\cdot b _ { x }$ 修改为 $y$ ；

$2 \textit { L R }$ —— 令初始序列为子段 $b [ L \ldots R ]$ ，询问其消除后长度。

请你输出所有询问的答案。

Input

第一行两个整数 ${ \mathrm { i } n } , q$ 。

第二行n 个整数 $b _ { 1 } , b _ { 2 } , \ldots , b _ { n }$

接下来 $: q$ 行，每行第一个整数 $\boldsymbol { o p t }$ 表示操作类型：

• 若 $\dot { \boldsymbol { o p t } } = 1$ ，后跟两个整数 $x , y ;$

• 若 $o p t = 2$ ，后跟两个整数 $\scriptstyle { \mathrm { ~ . ~ } } L , R$

Output

对于每个 $o p t = 2$ 的询问，输出一行一个整数，表示该子段的最优消除后长度。

Examples

<table><tr><td>standard input</td><td>standard output</td></tr><tr><td>6 5</td><td>3</td></tr><tr><td>3 1 4 1 5 9</td><td>3</td></tr><tr><td>2 1 6</td><td>4</td></tr><tr><td>1 4 2</td><td></td></tr><tr><td>2 1 6</td><td></td></tr><tr><td>1 3 8</td><td></td></tr><tr><td>2 2 5</td><td></td></tr><tr><td>10 6</td><td>4</td></tr><tr><td>9 8 8 2 7 1 8 9 4 3</td><td>4</td></tr><tr><td>2 1 10</td><td>5</td></tr><tr><td>1 4 9</td><td></td></tr><tr><td>2 1 10</td><td></td></tr><tr><td>1 3 7</td><td></td></tr><tr><td>1 5 8</td><td></td></tr><tr><td>2 3 10</td><td></td></tr></table>

## Note

$$
1 \leq n, q \leq 2 \times 1 0 ^ {5}, 1 \leq b _ {i}, y \leq 1 0 ^ {9}, 1 \leq x \leq n, 1 \leq L \leq R \leq n 。
$$

## Problem H. String

```txt
Input file: standard input
Output file: standard output
```

给定n 个字符串 $s _ { 1 } , s _ { 2 } , \ldots , s _ { n } \circ$

你可以以任意方式重新排列这n 个字符串，然后按该顺序将它们连接起来，得到一个字符串S。

对于从0 到L 的每个整数k（其中 $\begin{array} { r } { L = \sum _ { i = 1 } ^ { n } \left| s _ { i } \right| ) } \end{array}$ ，你可以独立地以任意方式重新排列这n 个字符串，按该顺序连接得到字符串S，然后最多修改S 中的k 个字符。一次修改中，你可以把S 中的一个字符替换成另一个小写英文字母。

你的任务是，对于每个k，找出能够得到的字典序最小的字符串。

## Input

第一行包含一个整数T $( 1 \leq T \leq 5 0 0 )$ ，表示测试用例的数量。

对于每个测试用例，第一行包含一个整数n $( 1 \leq n \leq 5 0 0 )$

第二行包含n 个非空字符串 $s _ { 1 } , s _ { 2 } , \ldots , s _ { n }$ ，字符串之间用空格分隔。每个字符串只包含小写英文字母。

对于每个测试用例，设 $\begin{array} { r } { L = \sum _ { i = 1 } ^ { n } | s _ { i } | } \end{array}$

保证所有测试用例中n 的总和不超过500，并且所有测试用例中L 的总和不超过500。

## Output

对于每个测试用例，输出 $L + 1$ 行。

第k 行 $( 0 \leq k \leq L )$ 输出在最多修改k 个字符后能够得到的字典序最小字符串。

每个测试用例的答案必须按k 递增的顺序输出，即从0 到L。

Example

<table><tr><td>standard input</td><td>standard output</td></tr><tr><td>3</td><td>aabbcaczz</td></tr><tr><td>5</td><td>aaabbcazz</td></tr><tr><td>bca a zz ab c</td><td>aaaaabczz</td></tr><tr><td>4</td><td>aaaaaabzz</td></tr><tr><td>ba b aa aba</td><td>aaaaaaaabc</td></tr><tr><td>3</td><td>aaaaaaaaab</td></tr><tr><td>az za m</td><td>aaaaaaaaaa</td></tr><tr><td></td><td>aaaaaaaaaa</td></tr><tr><td></td><td>aaaaaaaaaa</td></tr><tr><td></td><td>aaaaaaaaaa</td></tr><tr><td></td><td>aaababab</td></tr><tr><td></td><td>aaaaabab</td></tr><tr><td></td><td>aaaaaaab</td></tr><tr><td></td><td>aaaaaaaaaa</td></tr><tr><td></td><td>aaaaaaaaaa</td></tr><tr><td></td><td>aaaaaaaaaa</td></tr><tr><td></td><td>aaaaaaaaaa</td></tr><tr><td></td><td>aaaaaaaaaa</td></tr><tr><td></td><td>aaaaaaa</td></tr><tr><td></td><td>aaaaaaa</td></tr><tr><td></td><td>azmza</td></tr><tr><td></td><td>aaazm</td></tr><tr><td></td><td>aaaam</td></tr><tr><td></td><td>aaaaa</td></tr><tr><td></td><td>aaaaa</td></tr><tr><td></td><td>aaaaa</td></tr></table>

## Problem I. Rounddog II

```txt
Input file: standard input
Output file: standard output
```

你是Rounddog 的狂热粉丝，所以你要出一道关于Rounddog 的题目。

设 $T _ { 1 } = \tt R o u n d d o g$

对于每个整数i $> 1$ ，定义 ${ \cal T } _ { i } = { \cal T } _ { i - 1 } + \bf { g }$ ，其中+ 表示字符串拼接。

换句话说， $T _ { i }$ 是字符串<sub>Rounddo</sub> 后面紧跟着恰好i 个字符<sub>g</sub>。

给定一个字符串S 和一个整数k。考虑S 的所有循环移位。

字符串S 的一个循环移位是通过选择一个位置，并将该位置之前的前缀移动到字符串末尾得到的。例如，<sub>abcd</sub> 的循环移位有<sub>abcd</sub>、<sub>bcda</sub>、<sub>cdab</sub> 和<sub>dabc</sub>。

你的任务是统计有多少个S 的循环移位包含 $T _ { k }$ 作为一个连续子串。

## Input

第一行包含一个整数t $( 1 \leq t \leq 1 0 ^ { 5 } )$ ，表示测试用例的数量。

对于每个测试用例，第一行包含一个字符串S $\left( 1 \leq | S | \leq 1 0 ^ { 5 } \right)$

第二行包含一个整数k $( 1 \leq k \leq 1 0 0 )$

保证所有测试用例中|S| 的总和不超过 $1 0 ^ { 5 }$ ，并且S 只包含大写字母和小写字母。

## Output

对于每个测试用例，输出一个整数，表示包含 $T _ { k }$ 作为连续子串的循环移位数量。

## Example

<table><tr><td>standard input</td><td>standard output</td></tr><tr><td>3</td><td>12</td></tr><tr><td>Rounddogggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg</td><td>8</td></tr><tr><td>6</td><td>0</td></tr><tr><td>RounddogRounddo</td><td></td></tr><tr><td>1</td><td></td></tr><tr><td>abcdefgabcdegf</td><td></td></tr><tr><td>2</td><td></td></tr></table>

```txt
Problem J. Walk
Input file: standard input
Output file: standard output
```

给定一个包含n 个顶点和m 条边的简单连通无向图，以及一个特殊顶点序列 $\vert x _ { 1 } , x _ { 2 } , \dots , x _ { L }$ o

你希望从 $x _ { 1 }$ 出发，通过一个类似DFS 的过程，依次访问 $x _ { 1 } , x _ { 2 } , \ldots , x _ { L }$ 。你可以额外访问其他顶点，但必须按照给定顺序访问 $x _ { 1 } , x _ { 2 } , \ldots , x _ { L }$ o

该过程由一个栈定义。初始时，栈中只有 $\dot { x } _ { 1 }$ ，并认为 $x _ { 1 }$ 已被访问。每次操作中，你必须恰好执行以下两种操作之一：

• 设u 为当前栈顶。选择图中一个与u 相邻的顶点v，并将v 压入栈中。此时认为顶点v 被访问。

• 弹出当前栈顶顶点。如果弹出后栈非空，则认为新的栈顶顶点被访问。

最终栈中的内容不作要求。

在所有以最少操作次数依次访问 $x _ { 1 } , x _ { 2 } , \ldots , x _ { L }$ 的合法过程中，求过程中出现过的最大栈大小的最小可能值。

如果序列 中有若干个连续且相同的顶点，那么在第一次访问该顶点时，就认为这些连续出现的顶点均已被访问。

可以证明，最少操作次数为 $\textstyle \sum _ { i = 1 } ^ { L - 1 } \mathrm { d i s t } ( x _ { i } , x _ { i + 1 } )$ ，其中dist(a,b) 表示顶点a 与顶点b 之间最短路径的长度。

## Input

第一行包含一个整数T $( 1 \leq T \leq 6 0 )$ ，表示测试用例的数量。

对于每个测试用例，第一行包含三个整数n $( 2 ~ \leq ~ n ~ \leq ~ 2 0 0 ) ~ { \textrm { . } } m ~ ( n - 1 ~ \leq ~ m ~ \leq ~ \frac { n ( n - 1 ) } { 2 } )$ 和 $L ~ \left( 1 \leq L \leq 6 0 \right)$ ，分别表示顶点数、边数以及特殊顶点序列的长度。

接下来m 行，每行包含两个整数 $u ~ \left( 1 \leq u \leq n \right)$ 和v $( 1 \leq v \leq n )$ ，表示顶点u 和顶点v 之间存在一条无向边。

最后一行包含L 个整数 $x _ { 1 } , x _ { 2 } , . . . , x _ { L } ( 1 \leq x _ { i } \leq n )$

保证每个给定的图均为简单连通图。

同时保证所有测试用例中 $\textstyle \sum n \leq 2 0 0 , \operatorname { \mathrm { ~ H ~ } } \sum L \leq 6 0$ C

## Output

对于每个测试用例，输出一个整数，表示在所有使用最少操作次数的合法过程中，最大栈大小的最小可能值。

Example

<table><tr><td>standard input</td><td>standard output</td></tr><tr><td>4</td><td>5</td></tr><tr><td>5 4 5</td><td>4</td></tr><tr><td>1 2</td><td>3</td></tr><tr><td>2 3</td><td>4</td></tr><tr><td>3 4</td><td></td></tr><tr><td>4 5</td><td></td></tr><tr><td>1 3 5 4 2</td><td></td></tr><tr><td>6 7 6</td><td></td></tr><tr><td>1 2</td><td></td></tr><tr><td>2 3</td><td></td></tr><tr><td>3 4</td><td></td></tr><tr><td>4 5</td><td></td></tr><tr><td>5 6</td><td></td></tr><tr><td>6 1</td><td></td></tr><tr><td>2 5</td><td></td></tr><tr><td>1 4 6 3 5 2</td><td></td></tr><tr><td>7 6 6</td><td></td></tr><tr><td>1 2</td><td></td></tr><tr><td>1 3</td><td></td></tr><tr><td>1 4</td><td></td></tr><tr><td>1 5</td><td></td></tr><tr><td>1 6</td><td></td></tr><tr><td>1 7</td><td></td></tr><tr><td>2 3 4 5 6 7</td><td></td></tr><tr><td>5 10 4</td><td></td></tr><tr><td>1 2</td><td></td></tr><tr><td>1 3</td><td></td></tr><tr><td>1 4</td><td></td></tr><tr><td>1 5</td><td></td></tr><tr><td>2 3</td><td></td></tr><tr><td>2 4</td><td></td></tr><tr><td>2 5</td><td></td></tr><tr><td>3 4</td><td></td></tr><tr><td>3 5</td><td></td></tr><tr><td>4 5</td><td></td></tr><tr><td>1 5 3 2</td><td></td></tr></table>

## Problem K. Decomposition Trees

Input file: standard input Output file: standard output

给定一棵有n 个顶点的树T，顶点编号从1 到n。

我们递归地定义T 的一种点分树 如下。

对于T 的任意非空连通诱导子图S，任选一个顶点c ∈ S 作为当前分治中心。顶点c 成为S 的点分树的根。然后从S 中删除c。剩余的每个连通块都按照同样的规则独立分解，它们的点分树根都成为c 的子节点。

不同于通常的点分治，这里选取的分治中心c 不 必须是重心。当前连通块中的任意顶点都可以被选作中心。

如果两棵点分树作为同一顶点集合 $\{ 1 , 2 , \ldots , n \}$ 上的有根树，存在至少一个顶点的父亲不同，则认为它们不同。特别地，根不同的点分树一定不同。

你的任务是统计从T 中能够得到的不同点分树的数量。

由于答案可能非常大，请输出对10<sup>9</sup> +7 取模后的结果。

## Input

第一行包含一个整数n $( 1 \leq n \leq 3 0 0 0 )$

接下来的n−1 行中，每行包含两个整数u 和v $( 1 \leq u , v \leq n )$ ，表示顶点u 和v 之间有一条边。

保证给定图是一棵树。

## Output

输出一个整数：T 的不同点分树数量，对10<sup>9</sup> +7 取模。

Examples

<table><tr><td>standard input</td><td>standard output</td></tr><tr><td>3</td><td>5</td></tr><tr><td>1 2</td><td></td></tr><tr><td>2 3</td><td></td></tr><tr><td>5</td><td>51</td></tr><tr><td>1 2</td><td></td></tr><tr><td>1 3</td><td></td></tr><tr><td>2 4</td><td></td></tr><tr><td>2 5</td><td></td></tr><tr><td>7</td><td>605</td></tr><tr><td>1 2</td><td></td></tr><tr><td>1 4</td><td></td></tr><tr><td>2 3</td><td></td></tr><tr><td>2 5</td><td></td></tr><tr><td>4 6</td><td></td></tr><tr><td>5 7</td><td></td></tr></table>

```txt
Problem L. Geometry
Input file: standard input
Output file: standard output
```

给定平面上的一个凸多边形A。保证原点(0,0) 严格位于A 的内部。

另外给定m 个有价值的点。第i 个点为 $p _ { i } = ( x _ { i } , y _ { i } )$ ，其价值为正整数 ${ \bf \dot { \boldsymbol { a } } } _ { i }$ 。

对于一个实数 $\lambda \geq 0$ ，定义 $\lambda A = \{ \lambda p : p \in A \}$ ，也就是说，A 中每个点的每个坐标都相对于原点乘以λ。你需要找到最小的实数 $\lambda \geq 0$ ，使得可以画出一个闭圆盘C，满足以下两个条件：

$$
C \subseteq \lambda A;
$$

• C 中包含的给定点的总价值至少为W。

闭圆盘定义为形如 $C = \{ p \in \mathbb { R } ^ { 2 } : \| p - o \| _ { 2 } \leq r \}$ 的集合，其中o 是圆盘中心， $r \geq 0$ 是半径。

位于圆盘边界上的点也视为被圆盘包含。圆盘也允许与λA 的边界相切。

保证 $\textstyle 1 \leq W \leq \sum _ { i = 1 } ^ { m } a _ { i }$ ，因此答案一定存在且有限。

## Input

第一行包含一个整数T $( 1 \leq T \leq 1 0 0 )$ ，表示测试用例的数量。

对于每个测试用例，第一行包含三个整数n $( 3 ~ \leq ~ n ~ \leq ~ 1 0 0 0 ) \setminus m ~ ( 1 ~ \leq ~ m ~ \leq ~ 1 0 0 0 )$ 和W$\textstyle { \bigl ( } 1 \leq W \leq \sum _ { i = 1 } ^ { m } a _ { i } { \bigr ) }$

接下来的n 行描述凸多边形A。其中第j 行包含两个整数 $X _ { j }$ 和Y $( | X _ { j } | , | Y _ { j } | \le 1 0 ^ { 6 } )$ ，表示A 的第j 个顶点坐标。

多边形A 的顶点按逆时针顺序给出。该多边形是凸的，且原点严格位于其内部。

接下来的m 行描述关键点。第i 行包含三个整数 $x _ { i } \setminus y _ { i }$ 和 $\mid a _ { i } ~ ( \mid x _ { i } \mid , \mid y _ { i } \mid ~ \le ~ 1 0 ^ { 6 } , ~ 1 ~ \le ~ a _ { i } ~ \le ~ 1 0 ^ { 9 } )$ ，表示点 $( x _ { i } , y _ { i } )$ 的价值为 ${ \mathfrak { a } } _ { i }$ 。

保证所有测试用例中n 的总和不超过1000，所有测试用例中m 的总和不超过1000。

所有输入坐标和价值均为整数。W 的值可以用有符号64 位整数表示。

## Output

对于每个测试用例，输出一个实数：λ 的最小可能值。

如果你的答案的绝对误差或相对误差不超过10<sup>−6</sup>，则会被判定为正确。

更准确地说，若你的输出为x，正确答案为y，当 $| x - y | \leq 1 0 ^ { - 6 } \cdot \operatorname* { m a x } ( 1 , | y | )$ 时，你的答案将被接受。

Example

<table><tr><td>standard input</td><td>standard output</td></tr><tr><td>3</td><td>0.0000000000</td></tr><tr><td>4 1 5</td><td>1.0000000000</td></tr><tr><td>-1 -1</td><td>2.0000000000</td></tr><tr><td>1 -1</td><td></td></tr><tr><td>1 1</td><td></td></tr><tr><td>-1 1</td><td></td></tr><tr><td>0 0 5</td><td></td></tr><tr><td>4 2 2</td><td></td></tr><tr><td>-1 -1</td><td></td></tr><tr><td>1 -1</td><td></td></tr><tr><td>1 1</td><td></td></tr><tr><td>-1 1</td><td></td></tr><tr><td>1 0 1</td><td></td></tr><tr><td>0 1 1</td><td></td></tr><tr><td>4 2 2</td><td></td></tr><tr><td>-1 -1</td><td></td></tr><tr><td>1 -1</td><td></td></tr><tr><td>1 1</td><td></td></tr><tr><td>-1 1</td><td></td></tr><tr><td>-2 0 1</td><td></td></tr><tr><td>2 0 1</td><td></td></tr></table>