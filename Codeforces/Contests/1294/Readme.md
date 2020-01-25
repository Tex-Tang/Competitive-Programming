# CF 1294 (div 3)

## 1294A Collecting Coins
[Question](https://codeforces.com/problemset/problem/1294/A)

有三个人，他们各有 a, b, c 个 coins.
然后要分 n 个 coins 给他们三个人，使得 
```
A + a = B + a = C + c
A + B + C = n // A, B, C 是各分给他们的数量
```
### Idea
```
设 k 为 max(a, b, c)
若要使得 a = b = c，我们共需要
m = (k - a) + (k - b) + (k - c)
使得 a, b, c 变成 k 
a = b = c = max(a, b, c) = k

IF m < 0，他们无法达成平衡
IF m >= 0 && m % 3 == 0，他们可达成平衡
```

## 1294B Collecting Packages
[Question](https://codeforces.com/problemset/problem/1294/B)

有一个 Coordinate System (x-axis, y-axis)

起点为 (0, 0)，只可以 move up(U) 或 move right(R)

给 t 个 query，每个 query 给 n 个点 (x, y)，求最短 path，并 output 那个 path (lexicographically)

### Idea
从以上得知，
|  |  |  |  |  |
|---|---|---|---|---|
| 3 | - | x | - | - |
| 2 | - | - | - | x |
| 1 | - | x | - | - |
| 0 | s | - | - | - |
| - | 0 | 1 | 2 | 3 |

这个 graph 不可解，由于只能 move up 或 move right 当到达了 (1, 1) 他只能到 (1, 3) 或 (3, 2) 其中一点，一旦去了 (1, 3)就没办法到 (3, 2)了

也就是如果有解，必须确保
```
x_j < x_j+1 < x_j+2
y_j < y_j+1 < y_j+2
```
我们利用 3 个点来 prove (1, 1), (2, 2), (3, 3)

|  |  |  |  |  |
|---|---|---|---|---|
| 3 | - | - | - | x |
| 2 | - | - | x | - |
| 1 | - | x | - | - |
| 0 | s | - | - | - |
| - | 0 | 1 | 2 | 3 |

这样的情况一定有解

若 `x_j > x_j+1` AND `y_j < y_j+1` (2, 1), (1, 2), (3, 3)

|  |  |  |  |  |
|---|---|---|---|---|
| 3 | - | - | - | x |
| 2 | - | x | - | - |
| 1 | - | - | x | - |
| 0 | s | - | - | - |
| - | 0 | 1 | 2 | 3 |

这样的情况无解，因为我们只能 move up or move right

若 `x_j < x_j+1` AND `y_j > y_j+1` (1, 2), (2, 1), (3, 3)

|  |  |  |  |  |
|---|---|---|---|---|
| 3 | - | - | - | x |
| 2 | - | x | - | - |
| 1 | - | - | x | - |
| 0 | s | - | - | - |
| - | 0 | 1 | 2 | 3 |

同样无解

`x_j > x_j+1` AND `y_j > y_j+1` 不需要证明，因为和`x_j < x_j+1` AND `y_j < y_j+1` 没差。 

所以解题思路是 sort x 点，确保 `x_j < x_j+1`，然后 generate path
```
IF y_j > y_j+1 无解
IF y_j < y_j+1 有解
```

## 1294C Product of Three Numbers
[Question](https://codeforces.com/problemset/problem/1294/C)

给 t 个 query，每个 query 给一个数 n，求 a,b,c 使得 `a⋅b⋅c = n` 和 `2 <= a,b,c`

### Idea

```c++
for(int i = 2;i * i <= n;i++){
  if(n % i == 0){
    break;
  }
}
```

用 bruteforce 找两个 distinct divisors，limit 设在 i*i 因为最大的 divisor 就是 sqrt(n) 了，比如 18 可分解为
```
sqrt(18) = 4.243 ≈ 4
1 x 18 = 18
2 x 9 = 18
3 x 6 = 18
```

利用这个方法找到了两个 distinct divisor ，且 (n / a) / b 得到 c
```
IF a != b != c ，有解
ELSE 无解
```
因为可能找不到 a, b, c 若 n 是 prime number

### Additional

#### Sphenic Number

A Sphenic Number is a positive integer `n` which is product of exactly three distinct primes. which means a, b, c above must be prime number also.

All sphenic numbers have exactly eight divisors. If we express the sphenic number as `p⋅q⋅r = n`, where `p,q,r` are distinct primes, then the set of factor will be
`{1, p, q, r, pr, pq, qr, n}`

#### Idea
Find the 8 divisors, p,q,r using bruteforce, then check prime
```c++
vector<int> arr;
for(int i = 1;i * i <= n;i++){
  if(n % i == 0 && arr.size() < 8){
    arr.push_back(i); // 1, p, q, r
    arr.push_back(n / i); // n/1 = n, n/p = qr, n/q = pr, n/r = pq
  }
}
// arr = {1, n, p, qr, q, pr, r, pq}
if(arr.size() == 8 && (isPrime(arr[2]) && isPrime(arr[4]) && isPrime(arr[6]))){
  cout << "YES";
}else{
  cout << "NO";
}
```

## 1294D MEX maximizing
[Question](https://codeforces.com/problemset/problem/1294/D)

MEX of an array is a minimum non-negative integer that does not belong to the array. Given x, we can choose any element in array and do operation +x or -x
- [1,2,3,4] MEX = 0
- [0,1,4,3] MEX = 2
- [0,0,1,0,2] MEX = 3

Give q queries and an integer x, every query consist of one integer y. the y will be added into array. For example
```
7 3
0  // arr = {0} MEX = 1
1  // arr = {0, 1} MEX = 2
2  // arr = {0, 1, 2} MEX = 3
2  // arr = {0, 1, 2, 2} MEX = 3
0  // arr = {0, 1, 2, 2, 3} MEX = 4 since x = 3, so 0 + 3 = 3
0  // arr = {0, 1, 2, 2, 3, 0} MEX = 4
10 // arr = {0, 1, 2, 5, 3, 6, 4} MEX = 7
```

### Idea
We can create an mods array for storing the mod of y % x. get the min(mods) and * x
```
7 3
0  // mods = {1, 0, 0} MEX = 1
1  // mods = {1, 1, 0} MEX = 2
2  // mods = {1, 1, 1} MEX = 1*3 = 3
2  // mods = {1, 1, 2} MEX = 1*3 = 3
0  // mods = {2, 1, 2} MEX = 1*3 + 1 = 4
0  // mods = {3, 1, 2} MEX = 1*3 + 1 = 4
10 // mods = {3, 2, 2} MEX = 2*3 + 1 = 7
```

`{1,0,0}` can say that our array can go `{0},{x},{2x},{3x}` so MEX is 1

`{1,1,0}` can say that our array can do combination of `{0},{x},{2x},{3x}` and `{1},{x+1},{2x+1},{3x+1}` so MEX is 2

`{1,1,1}` can say that our array can do combination of `{0},{x},{2x},{3x}` and `{1},{x+1},{2x+1},{3x+1}` and `{2},{x+2},{2x+2},{3x+2}` so MEX is 3

## 1294E Obtain a Permutation
[Question](https://codeforces.com/problemset/problem/1294/E)

### Idea
From the question, we know that we only need to focus on each column, and make the column to become standard column.

If we shift i times, the number of moves is i + n, which we assume we shift i times and change all the elements (n elements) to obtain the standard column.
`count[i] = i + n`

And we loop the row by row in each column, first we determine whether if the element belongs to the column. Ex: 
```
3 3
3 2 1
1 2 3
4 5 6
```
3 is belongs to the third column

5 is belongs to the second column.

Next, if the element,a is belongs to the column, we need to calculate how many shift will move the element to the standard column.
```c++
// i = standard row
// row = current row
if(row < n){
  if(i >= row){ // if standard row >= current row
    count[i - row]--; // shift i - row times
  }else{        // if standard row < current row
    count[n - (row - i)]--; // shift n - (row - i) times
  }
  // can modify to count[(i - row + n) % n]--;
}
```
So the minimun moves for each column is 
```c++
for(int i = 0;i < n;i++){
  curr = min(curr, count[i]);
}
```
`ans = sum of minimun moves for each column`

## 1294 F Three Paths on a Tree
[Question](https://codeforces.com/problemset/problem/1294/F)

A graph with n vertices and given n - 1 edges, 找三个 vertices 能到的最远距离。Refer to the link above.

### Idea
Find diameter of graph using DFS
```
5
1 2
2 3
3 4
4 5
// 1 -> 2 -> 3 -> 4 -> 5
```
From the input above, we can conclude the length is `n-1` and the three vertices is both end and a random vertex.

```
8
1 2
2 3
3 4
4 5
4 6
3 7
3 8
1 -> 2 -> 3 -> 4 -> 6
          |    |   
          -> 7 -> 5
          -> 8
```

so the diameter is 5, either `1->6` or `1->5` or `1->8`
and the third point must be the furthest, so we can do combinations
```
1 -> 6 then 3th point is 8
1 -> 5 then 3th point is 8
1 -> 8 then the third point is either 6 or 5
```
We can find the third point by using BFS and get the furthest point.