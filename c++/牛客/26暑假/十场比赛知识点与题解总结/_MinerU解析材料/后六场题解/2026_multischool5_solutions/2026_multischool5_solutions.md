## 2026 牛客 暑期多校训练营 5

哈尔滨工业大学命题组

## Ã - Echo Prefixes

## 题目大意

■ 固定字符串 S，每个后缀起点 i 有可修改权值 $a_{i}$ 。

■ 子串 X 的回声值为所有出现位置起点权值之和:

$$
H (X) = \sum_ {S [ j.. j + | X | - 1 ] = X} a _ {j}.
$$

■ 查询某个后缀的前 $m$ 个前缀回声值之和，或找到前缀和首次达到 $k$ 的长度。

■ $n, q \leq 2 \times 10^{5}$ ，需要支持单点修改与在线查询。

## Ã - Echo Prefixes

## 后缀树上的路径模型

■ 用后缀数组和 LCP 建出压缩后缀树；后缀 $S[p..n]$ 对应一片叶子。

■ 对树结点 v 定义

$$
W _ {v} = \sum_ {i \in \operatorname{subtree} (v)} a _ {i}.
$$

它正是结点所代表子串的 H 值。

■ 压缩边 $(\mathrm{fa}(v), v)$ 上的所有字符串拥有相同出现集合，因此贡献为

$$
\left(\mathrm{dep} _ {v} - \mathrm{dep} _ {\mathrm{fa} (v)}\right) W _ {v}.
$$

■ 所求前缀和就是根到对应叶子的加权路径和，并在深度 $m$ 处截断。

## Ã - Echo Prefixes

## 维护与查询

■ 修改 $a_{i} \leftarrow a_{i} + \Delta$ ：后缀叶子 $i$ 到根路径上的所有 $W_{v}$ 加 $\Delta$ 。

■ 树链剖分后，线段树维护边长系数和 $\sum len_{v} W_{v}$ ，支持路径加、路径和。

■ 倍增找到深度 m 所在压缩边；最后一段按实际长度补贡献。

■ 第三类询问按根到叶的重链顺序扫描，并在线段树内二分第一个使前缀和达到 k 的位置。

■ 建树 $\mathcal{O}(n\log n)$ ，每次操作 $\mathcal{O}(\log^{2}n)$ ，空间 $\mathcal{O}(n)$ 。

## B - Enlarged Badge

## 题目大意

■ 给定两个整点集的凸包 P, Q。

■ 对每个 k，统计整数平移向量 t，使得 $(kP + t) \cap Q \neq \varnothing$ 。

■ 边界相交也计入，k 可达 $10^{18}$ ，询问数可达 $2 \times 10^{5}$ 。

关键是把“两个多边形相交”变成一个固定凸多边形中的整点计数。

## B - Enlarged Badge

## Minkowski 和

■ 存在 $p \in P, q \in Q$ 使 $kp + t = q$ ，等价于

$$
t \in Q + (- k P).
$$

因而答案是整点多边形 $R_{k} = Q + (-kP)$ 中的格点数。

先求凸包，再按极角归并两凸多边形边向量，可在线性时间求Minkowski和。

■ 只需显式计算一次 $R_{1} = Q + (-P)$ ，之后每个询问代入关于 k 的多项式。

## B - Enlarged Badge

## Pick 定理与二次多项式

记 $S(X)$ 为二倍面积， $B(X)$ 为边界格点数。Pick 定理给出

$$
\# (X \cap \mathbb {Z} ^ {2}) = \frac {S (X) + B (X) + 2}{2}.
$$

Minkowski 混合面积与边界长度满足

$$
\begin{array}{l} S (R _ {k}) = S (Q) + k ^ {2} S (P) + k C, \\ B (R _ {k}) = B (Q) + k B (P), \end{array}
$$

其中

$$
C = S (R _ {1}) - S (Q) - S (P).
$$

所以答案是关于 k 的二次多项式，模 998244353 直接计算即可。

## B - Enlarged Badge 实现细节

■ 凸包去重，并删除边界上的共线中间点。

■ 面积叉积使用 \_\_int128，避免坐标乘法溢出。

■ 边界格点数：每条边贡献 $\gcd(|\Delta x|, |\Delta y|)$ 。

■ 预处理 $\mathcal{O}((n+m)\log(n+m))$ ；每个询问 $\mathcal{O}(1)$ ；空间 $\mathcal{O}(n+m)$ 。

## C - Number

## 题目大意与必要条件

构造三个 $0,1,\ldots ,B - 1$ 的排列 $P,Q,R$ ，满足 $[P]_B + [Q]_B = [R]_B$ ，且每列三个数字互异。

令进入第 j 位的进位为 $c_{j}$ ，则

$$
p _ {j} + q _ {j} + c _ {j} = r _ {j} + B c _ {j + 1}, \qquad c _ {0} = c _ {B} = 0.
$$

三个排列的数位和均为 $S = B(B - 1) / 2$ 。对所有列求和，设内部进位总数为 $C$ :

$$
2 S + C = S + B C \Longrightarrow C = \frac {B}{2}.
$$

所以 $B$ 必须为偶数；结合列内互异，只有偶数 $B \geq 4$ 有解。

## C - Number

## 按列构造

对 $B \geq 6$ 令 n = B/2，用 $p = 0, \ldots, B - 1$ 标识列：

$$
q _ {p} = (p - 2) \bmod B, \qquad a _ {p} = \left\{ \begin{array}{l l} 1, & p <   n, \\ 0, & p \geq n, \end{array} \right.
$$

并交换 $a_1, a_{n+1}$ ，从而 $a_{p+n} = 1 - a_p$ 且恰有 $n$ 个入进位。

$$
s _ {p} = p + q _ {p} + a _ {p}, \qquad r _ {p} = s _ {p} \bmod B, \qquad d _ {p} = \lfloor s _ {p} / B \rfloor .
$$

$B = 4$ 单独给出一组构造。

## C - Number为什么三个序列都是排列

$q_{p}=(p-2)\bmod B$ 显然是排列。

■ 模 B 有 $r_{p} \equiv 2p - 2 + a_{p}$ 。把 p = x 与 $p = x + n$ 配对，得到

$$
\left\{r _ {x}, r _ {x + n} \right\} = \left\{2 x - 2, 2 x - 1 \right\} \pmod {B}.
$$

因而偶数、奇数各遍历一次，R 也是排列。

■ 特殊调整保证 $p \neq q_{p}$ 、 $p \neq r_{p}$ 、 $q_{p} \neq r_{p}$ 。

## C - Number 恢复列顺序

■ 每列看成一条有向边 $a_{p} \rightarrow d_{p}$ ，相邻列要求“出进位等于下一列入进位”。

因为 $\sum a_{p} = \sum d_{p} = B/2$ ，边 $0 \rightarrow 1$ 与 $1 \rightarrow 0$ 数量相等。

■ 在只有两个点的有向多重图上求一条从 0 出发的欧拉回路，即得到从低位到高位的列顺序。

构造与恢复均为 $\mathcal{O}(B)$ 。

## D - Half-plane Cover 补集、Helly 与 Farkas

选择若干闭半平面的并覆盖全平面，等价于它们的开补半平面交为空。二维 Helly 定理说明：若交为空，则至多取三个就已经为空，因此最优答案只可能是 2 或 3。Farkas 引理给出等价条件：存在 $\lambda_{i} \geq 0$ ，使

$$
\sum_ {i} \lambda_ {i} a _ {i} = 0, \quad \sum_ {i} \lambda_ {i} b _ {i} = 0, \quad \sum_ {i} \lambda_ {i} c _ {i} \geq 0.
$$

归一化 $\sum_{i}\lambda_{i} = 1$ 后，这是一个只有三条等式约束的线性规划。

## D - Half-plane Cover 先检查所有二元答案

■ 两个法向量必须平行且方向相反：

$$
a _ {i} b _ {j} - b _ {i} a _ {j} = 0, \qquad a _ {i} a _ {j} + b _ {i} b _ {j} <   0.
$$

■ 再按两法向量的缩放比例检查常数项，判断两个闭半平面之间是否没有空隙。

■ 枚举全部点对，若存在则答案必为最优的 2。

■ 全程使用整数叉积和乘法，避免斜率与浮点误差。

## D - Half-plane Cover

## 三元答案化为线性规划

若不存在二元解，考虑多面体

$$
\mathcal {P} = \{\lambda \geq 0: \sum \lambda_ {i} (a _ {i}, b _ {i}, 1) = (0, 0, 1) \}.
$$

在 $\mathcal{P}$ 上最大化 $\sum_{i}\lambda_{i}c_{i}$ :

■ 最优值 $\geq 0$ 当且仅当存在覆盖;

■ 基可行解至多含三个非零变量，正好给出要输出的三个下标；

■ 先在法向量凸包中找包含原点的三角形，得到初始基；再做三变量单纯形换基。

## D - Half-plane Cover 精确实现与复杂度

■ Cramer 法则计算基解、方向和约化费用，只比较行列式与分数。

■ 使用 Bland 规则选择入基变量，处理退化并避免循环。

■ 最后再用整数 Farkas 系数验证输出的三元组。

■ 点对检查 $\mathcal{O}(n^{2})$ ；单纯形每次换基 $\mathcal{O}(n)$ ，空间 $\mathcal{O}(n)$ 。

## É - Koishi and Function 只与质因子总数有关

■ 记 $\Omega(n)$ 为 $n$ 的质因子个数（计重数）。

■ 归纳可证 $g(n)$ 只依赖 $\Omega(n)$ ，记 $h_{m}=g(n)$ ( $\Omega(n)=m$ )。

■ $n$ 的任意非平凡乘法分解对应于 $m$ 的一个至少含两项的正整数拆分；反之可把质因子分组实现任意拆分。

因而

$$
h _ {m} = \operatorname{mex} \left(\{0 \} \cup \left\{\prod_ {j} h _ {x _ {j}}: \sum_ {j} x _ {j} = m, \# j \geq 2 \right\}\right).
$$

## $\tilde{E}$ - Koishi and Function

## 预处理小状态

■ $n \leq 10^{7}$ , 所以 $\Omega(n) \leq \lfloor \log_{2} n \rfloor \leq 23$ 。

■ 对每个 m DFS 枚举整数拆分，收集各部分 h 值之积并取 mex。

■ 状态数极小，这部分可以直接暴力；无需对每个整数枚举因数分解。

■ 初值 $h_0 = g(1) = 1$ ，质数对应 $h_1 = 1$ 。

## $\bar{E}$ - Koishi and Function

## 线性筛统计答案

■ 线性筛维护最小质因子 $\mathrm{lp}(i)$ ，并递推

$$
\Omega (i) = \Omega (i / \mathrm{lp} (i)) + 1.
$$

■ 顺序维护 $c^i$ ，累加

$$
\sum_ {i = 1} ^ {N} h _ {\Omega (i)} c ^ {i} \pmod {9 9 8 2 4 4 3 5 3}.
$$

■ 时间 $\mathcal{O}(N)$ ，空间 $\mathcal{O}(N)$ 。

## F - Four 核心恒等式

设 $x = \gcd(i, j)$ , $y = \gcd(j, k)$ , $z = \gcd(k, l)$ 。利用

$$
\operatorname{lcm} (x, y, z) = \frac {x y z \operatorname * {g c d} (x , y , z)}{\operatorname * {g c d} (x , y) \operatorname * {g c d} (y , z) \operatorname * {g c d} (x , z)}
$$

以及本题中 $\gcd (x,z) = \gcd (x,y,z)$ ，得到

$$
\operatorname{lcm} (x, y, z) = \frac {\operatorname* {g c d} (i , j) \operatorname* {g c d} (j , k) \operatorname* {g c d} (k , l)}{\operatorname* {g c d} (i , j , k) \operatorname* {g c d} (j , k , l)}.
$$

令 $g = \gcd(j, k)$ , j = ga, k = gb, $(a, b) = 1$ ，则 i 与 l 两侧完全分离。

## F - Four

## 处理单侧求和

定义

$$
F (g, a) = \sum_ {i = 1} ^ {A} i ^ {p _ {1}} \operatorname * {g c d} \left(\frac {i}{\operatorname* {g c d} (i , g)}, a\right).
$$

用 $\gcd (x,a) = \sum_{d|x,d|a}\varphi (d)$ ，并定义

$$
Q (g, d) = d \prod_ {q | d} q ^ {v _ {q} (g)}.
$$

逐质因数分析可得

$$
d \mid \frac {i}{\operatorname* {g c d} (i , g)} \iff Q (g, d) \mid i.
$$

于是问题化为幂和前缀与Dirichlet前缀和；右侧同理。

## F - Four

## 合并与 Möbius 反演

最终形式为

$$
\sum_{g}g\sum_{\substack{a\leq B / g, b\leq C / g\\ (a,b) = 1}}(ga)^{p_{2}}(gb)^{p_{3}}F(g,a)G(g,b).
$$

使用

$$
[ \operatorname * {g c d} (a, b) = 1 ] = \sum_ {t | a, t | b} \mu (t)
$$

消去互质限制，整理后用 Dirichlet 后缀和批量计算。

总复杂度 $\mathcal{O}(n\log n\log\log n)$ ，其中 $n=\max(A,B,C,D)$ 。

## G - Bipartite Graph 最小点覆盖转最小割

■ 建网络： $s \rightarrow L$ 容量 1， $L \rightarrow R$ 容量 $+\infty$ ， $R \rightarrow t$ 容量 1。

■ 最小割与二分图最小点覆盖一一对应。

■ 左点在汇侧表示被选，右点在源侧表示被选；查询中的“选/不选”因此转成顶点必须位于割的某一侧。

## G - Bipartite Graph 所有最小割的结构

■ 跑一次最大流后，在残量网络中缩强连通分量，得到 DAG。

■ 一个源侧集合 S 合法，当且仅当它在残量 DAG 上后继闭合。

■ 强制某点在 S: 它能到达的所有点都必须在 S。

■ 强制某点在 T: 所有能到达它的点都必须在 T。

■ 两类闭包相交则无解，否则存在满足要求的最小点覆盖。

## G - Bipartite Graph

## 强制集合计数

■ 对缩点 DAG 预处理可达集合与反向可达集合。

■ 查询时合并所有要求形成的两类闭包；闭包大小对应“必选”和“必不选”顶点数。

■ 用 bitset 做 DAG 可达性；内存不足时对点分块，得到根号级空间。

■ 复杂度

$$
\mathcal {O} \left((n + m) \sqrt {n} + \frac {n + m + \sum T}{\omega}\right).
$$

## H - Count it 序列形状与合法性

$P_{i}$ 单调不降， $Q_{i}$ 单调不升，所以 $B_{i} = \min (P_{i},Q_{i})$ 必须是单峰序列：

$$
B _ {1} \leq \dots \leq B _ {L} = \dots = B _ {R} \geq \dots \geq B _ {N - 1}.
$$

令 $K = \max B_{i}$ 。还必须满足

$$
B _ {i} \leq \min (i, N - i, M).
$$

否则答案为0。平台切口为 $L,\dots ,R$ ，左右两端都必须包含 $0,\ldots ,K - 1$ 。

## H - Count it 分解为左右端与中间

设 $d = R - L$ 。定义：

■ $F_{L}$ ：左端各前缀 mex 恰为给定值，且最终 mex 为 K;

■ $G_{L}$ ：前面给定值满足，最后 mex 严格大于 K;

■ 反转右端后同理得到 $F_{R}, G_{R}$ 。

平台上 K 不能同时出现在切口两侧。令 z = M - [K < M]，中间不取 K 时每格有 z 种选择。

## H - Count it

## 三种情况合并

左右端均无 K 时，中间至多出现一个 K:

$$
H = z ^ {d} + [ K <   M ] \cdot d z ^ {d - 1}.
$$

若 $K$ 已在左端或右端，中间不能再出现 $K$ 。因此总答案为

$$
\boxed {F _ {L} F _ {R} H + (G _ {L} F _ {R} + F _ {L} G _ {R}) z ^ {d}}.
$$

问题只剩如何计算一个给定非降前缀 mex 序列的 F, G。

## H - Count it

## 前缀 mex 的容斥 DP

给定 $m_{1} \leq \cdots \leq m_{t}$ ，令 $m_{0} = 0$ 。

若 $m_{i} > m_{i - 1}$ ，则 $A_{i} = m_{i - 1}$ ；被跳过的 $m_{i - 1} + 1,\dots ,m_i - 1$ 必须已出现。

■ 若 $m_{i} = m_{i-1}$ ，该位置自由，但当前及未来会成为 mex 的值不能提前出现。

■ 对“某个被跳过值尚未出现”做容斥；从后向前扫描， $dp_{k}$ 表示选了 k 个坏事件的带符号方案数。

■ 自由位置乘可选数 $M - h_i - k$ ；新增 $g$ 个坏事件等价于生成函数乘 $(1 - x)^g$ ：

$$
d p _ {k} ^ {\prime} = d p _ {k} - d p _ {k - 1}.
$$

总复杂度 $\mathcal{O}(N^{2})$ ，空间 $\mathcal{O}(N)$ 。

## I - Sequence Operation 2 不变量与目标

■ 操作翻转 x, y, z，且 $x = y \oplus z$ 。

■ 所有值为 1 的位置编号异或和保持不变。

因而若该异或和非零，最终不可能全为 0；“至多剩一个 1”正是可达到的最优目标。

## I - Sequence Operation 2 从小到大扫描构造

维护 pos: 在已扫描区间内唯一可能为 1 的位置，不存在则为 -1。

■ 若 $s_{i}=0$ ，跳过操作 $i_{0}$ 。

■ 若 $s_i = 1, pos = -1$ ，令 $pos = i$ 。

■ 否则执行 $(i, pos, i \oplus pos)$ ：若 $i \oplus pos < i$ ，更新 $pos = i \oplus pos$ ；否则已扫描区间清零。

每个操作编号至多使用一次，总复杂度 $\mathcal{O}(N)$ 。

## I - Sequence Operation 2 另一种按位理解

■ 从高位到低位，把当前最高位为1的位置两两配对。

■ 两个同最高位编号异或后会消去该最高位，问题被递归压到低位。

■ 每层最多留下一个未配对位置；这些剩余位置最高位两两不同，再从低到高合并。

■ 这也解释了为什么 $N = 2^{n} - 1$ 的编号集合在异或下足够封闭。

## J - Sequence (Median Version) 阈值化

■ 对阈值 T，把 $a_{i} \geq T$ 记为 1，否则记为 0。

■ 中位数变换与任意阈值化可交换，因此只需研究环形 01 序列的多数变换。

■ 相邻的 00 或 11 在之后永不改变，称为“源”。

## J - Sequence (Median Version) 源向交替段传播

■ 两个源之间只可能是 0101... 的交替连续段。

■ 每次变换等价于两端源向段内传播一步；若传播相遇，剩余部分由奇偶性决定。

例如

00010101010111 $\longrightarrow$ 00001010101111.

■ 因而给定阈值后，可直接计算 $k$ 次变换后的所有01答案。

## J - Sequence (Median Version)

## 离线枚举阈值

■ 从大到小枚举 $a_{i}$ 中出现的值，动态把位置从0改成1。

■ 只维护阈值变化时合并、分裂的交替段，以及段内尚未确定的奇偶位置。

■ 用并查集/线段树批量给未赋值位置填入当前阈值。

■ 每个位置只被确定常数次，时间 $\mathcal{O}(n\log n)$ ，空间 $\mathcal{O}(n)$ 。

## K - Sequence (Mex Version) 周期性结论

■ 记一次变换为 T，第 t 层序列为 $a^{(t)}$ 。

■ 核心结论:

$$
\boxed {a ^ {(t + 2)} = a ^ {(t)} \qquad (t \geq 3).}
$$

因而只需模拟到第4层，再根据 $k$ 的奇偶性选择答案。

## K - Sequence (Mex Version)

## 引理一：隔层单调不增

固定 $x = a_{i}^{(t)}$ 。计算下一层 i - 1, i, $i + 1$ 三个位置时，输入集合都包含 x，所以这三个新值都不等于 x。

于是计算 $a_{i}^{(t + 2)}$ 时，候选集合中缺少 $x$ 。由 mex 定义：

$$
\boxed {a _ {i} ^ {(t + 2)} \leq a _ {i} ^ {(t)}}.
$$

该不等式对所有位置逐点成立。

## K - Sequence (Mex Version) 引理二：严格下降可以向前追溯

若 $a_{i}^{(t + 2)} = x < a_{i}^{(t)}$ ，则 $x$ 必在计算 $a_{i}^{(t)}$ 的上一层邻域中。所以存在 $j\in \{i - 1,i,i + 1\}$ 使

$$
a _ {j} ^ {(t - 1)} = x.
$$

另一方面，mex 在第 $t + 2$ 层等于 $x$ ，说明第 $t + 1$ 层该邻域没有 $x$ 。结合引理一：

$$
a _ {j} ^ {(t + 1)} <   x.
$$

即每追溯一次，会得到一个更小的非负整数。

## K - Sequence (Mex Version)

## 证明进入二周期

一次只对三个数取 $\mathrm{mex}$ ，因此 $t \geq 1$ 时所有值均不超过3。

若存在 $a_{i}^{(5)} < a_{i}^{(3)}$ ，记较小值为 $x_0 \leq 2$ 。连续三次应用引理二得到

$$
0 \leq x _ {3} <   x _ {2} <   x _ {1} <   x _ {0} \leq 2,
$$

但 $\{0,1,2\}$ 中不可能有四个严格递减非负整数，矛盾。

故 $a^{(5)} = a^{(3)}$ ；变换确定，因此之后始终以不超过2的周期循环。总复杂度 $\mathcal{O}(n)$ 。

## L - Matrix

## 答案候选

■ 每次路径必经过 $(1,1)$ ，并在第二步经过 $(1,2)$ 或 $(2,1)$ 。

■ 若最终值为 $X$ 、操作次数为 $K$ ，则

$$
X = a _ {1, 1} + K, \quad 2 X = a _ {1, 2} + a _ {2, 1} + K.
$$

■ 消元得到唯一候选

$$
\boxed {K = a _ {1, 2} + a _ {2, 1} - 2 a _ {1, 1}.}
$$

边界为单行或单列时单独处理。

## L - Matrix

## 按反对角线分层

把格点按 $i+j=s$ 分层。设当前层每行需要通过的路径数量为 $b_{i}$ ，下一层目标为 $c_{i}$ 。每个来自行 i 的单位只能流向下一层的行 i 或 $i+1$ 。令

$$
B _ {r} = \sum_ {i \leq r} b _ {i}, \quad C _ {r} = \sum_ {i \leq r} c _ {i}.
$$

存在分配当且仅当对所有 $r$

$$
\boxed {B _ {r - 1} \leq C _ {r} \leq B _ {r}}.
$$

## - Matrix

## 验证算法

■ 由候选最终值 X 得到每个格点必须经过的路径次数 $X - a_{i,j}$ 。

■ 从左上到右下逐层贪心分配流量，或直接检查每层的前缀和条件。

■ 任一数量为负、总量不守恒或前缀条件失败，则输出 -1；否则输出 K。

■ 时间 $\mathcal{O}(nm)$ ，额外空间 $\mathcal{O}(\min(n,m))$ 。

## M - Je t'aime encore 树的生成函数

在 $F_{2}$ 上，设 $B_{h}(z)$ 为根权值不超过 h 的满三叉平面树生成函数， $E_{h}=B_{h}+B_{h-1}$ 表示根权值恰为 h。

根为内部结点时，要么三个儿子权值均不超过 $h - 1$ ，要么恰有一个儿子权值为 $h$ 。化简得

$$
B _ {h} = 1 + z B _ {h} B _ {h - 1} ^ {2}, \qquad \boxed {B _ {h} (z) = \frac {1}{1 + z B _ {h - 1} (z) ^ {2}}.}
$$

## M - Je t'aime encore

## $Q_{h}$ 的闭式结构

定义

$$
Q _ {0} = 1, \qquad Q _ {1} = 1 + z, \qquad Q _ {h} = Q _ {h - 1} + z ^ {2 ^ {h - 1}} Q _ {h - 2}.
$$

可归纳证明

$$
B _ {h} = \frac {Q _ {h - 1} ^ {2}}{Q _ {h}}, \qquad E _ {h} = \frac {z ^ {2 ^ {h} - 1}}{Q _ {h} Q _ {h - 1}}.
$$

$Q_{h}$ 也可解释为“二进制位中无相邻1”的指数生成多项式。只需保留到 $z^{N}$ ，因此有效递推层数仅 $\mathcal{O}(\log N)$ 。

## M - Je t'aime encore 蓝色结点形成一条链

权值为 $H$ 的内部结点只可能沿一个儿子继续保持权值 $H$ ，所以所有蓝点形成从根向下的一条链。

用 $u$ 记录蓝点数：非末端蓝点贡献 $uzB_{H - 1}^2$ ，末端蓝点贡献 $uzB_{H - 1}E_{H - 1}^2$ 。于是

$$
F _ {H} (z, u) = \frac {u z B _ {H - 1} (z) E _ {H - 1} (z) ^ {2}}{1 + u z B _ {H - 1} (z) ^ {2}}.
$$

提出最小结点数 $2^{H} - 1$ 后再处理额外的 $N$ 个结点。

## M - Je t'aime encore 转成统一的系数提取

令 $D(z)=Q_{H-1}(z)$ 。化简得到

$$
G _ {H} (z, u) = \frac {u}{D (z) ^ {3}} \cdot \frac {1}{1 + u R (z)}, \qquad R (z) = \frac {Q _ {H} (z) + D (z) ^ {2}}{D (z) ^ {2}}.
$$

所以恰有 $k$ 个蓝点的答案为

$$
\boxed {\operatorname{ans} _ {k} = \left[ z ^ {N} \right] D (z) ^ {- 3} R (z) ^ {k - 1}}.
$$

难点变成在特征2下批量处理复合与复合逆。

## M - Je t'aime encore 利用特征 2 的特殊结构

由 $B_{H}$ 的递推可得

$$
R (z) = z U (z), \qquad U (z) = B _ {H - 1} (z) ^ {2}.
$$

因此 $U(0)=1$ 且在 $F_{2}$ 中 $U'(z)=0$ 。令 $h=R^{(-1)}$ ，两次另类 Lagrange 反演可把答案转成

$$
\mathrm{ans} _ {k} = [ z ^ {m} ] A (z) V (z) ^ {m}, \qquad m = N - k + 1,
$$

其中 A, V 都可由 D, U 通过多项式运算得到。

## M - Je t'aime encore

对角线系数递归

对

$$
s _ {n} = [ x ^ {n} ] A (x) V (x) ^ {n}
$$

定义偶、奇抽取算子

$$
\Lambda_ {0} \left(\sum a _ {i} x ^ {i}\right) = \sum a _ {2 i} x ^ {i}, \quad \Lambda_ {1} \left(\sum a _ {i} x ^ {i}\right) = \sum a _ {2 i + 1} x ^ {i}.
$$

利用 $V(x)^{2}=V(x^{2})$ :

$$
s _ {2 m} = [ x ^ {m} ] \Lambda_ {0} (A) V ^ {m}, \qquad s _ {2 m + 1} = [ x ^ {m} ] \Lambda_ {1} (A V) V ^ {m}.
$$

递归折半即可同时求出全部需要的系数。

## M - Je t'aime encore

## 复杂度与关键恒等式

■ 多项式乘法、求逆使用 NTT；每层规模折半。

■ 总复杂度 $\mathcal{O}(M(N)\log N)$ ，空间 $\mathcal{O}(N)$ 。

■ 证明闭式时使用恒等式

$$
Q _ {h} = Q _ {h - 1} ^ {2} + z Q _ {h - 2} ^ {4},
$$

它对应无相邻二进制位集合中“最低位不选/选”的分类。

## ■ 进一步可归纳出

$$
Q _ {h - 1} ^ {3} + Q _ {h} Q _ {h - 2} ^ {2} = z ^ {2 ^ {h} - 1},
$$

从而得到 $E_{h}$ 的闭式。

## Ñ - Welcome to HIT

## 题目大意

■ 清华大学的英文缩写是 THU，北京大学的英文缩写是 PKU。

■ 哈尔滨工业大学的英文名是 Harbin Institute of Technology。

■ 本题没有输入，输出其大写英文缩写。

## N - Welcome to HIT 题解

## HIT

时间复杂度 $\mathcal{O}(1)$ ，空间复杂度 $\mathcal{O}(1)$ 。

## THANKS!

AC.NOWCODER.COM