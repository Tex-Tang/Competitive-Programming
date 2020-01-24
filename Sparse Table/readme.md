# Sparse Table
## 概念

`[2, 14]`

2 到 14 length = 13

13 = (1101) = 8 + 4 + 1

所以就可以分成 [2, 9] ∪ [10, 13] ∪ [14, 14]

log2(13) = 3 就是说可以分成三个 interval

Sparse Table 也是一样

## Precomputation

`st[i][j]` 会 store [i, i + 2^j - 1] of length 2^j

```c++
st[1][1] // range([1, 2])
st[1][2] // range([1, 4])
st[1][3] // range([1, 8])
st[1][4] // range([1, 16])
st[2][1] // range([2, 3])
st[2][2] // range([2, 5])
st[2][3] // range([2, 9])
st[2][4] // range([2, 17])
```

```c++
int st[MAXN][K + 1]
```
MAXN = length of array

K = log2(MAXN) + 1 because 2^(log2(MAXN)) is the biggest power of two range.

Since the `range(i, i + 2^j - 1)` can split nicely into 
```
range(i, i + 2^(j - 1) - 1)  
range(i + 2^(j - 1), i + 2^j - 1)
Eg: range(1, 16) split into (1, 8) + (9, 16)
```
so we can generatee the table efficiently using DP:
```c++
for (int i = 0; i < N; i++)
    st[i][0] = f(array[i]);

for (int j = 1; j <= K; j++){
  for (int i = 0; i + (1 << j) <= N; i++){
    st[i][j] = f(
      st[i][j - 1],                 // range(i, i + 2^(j - 1) - 1)
      st[i + (1 << (j - 1))][j - 1] // range(i + 2^(j - 1), i + 2^j - 1)
    );
  }
}
st[0][1] = f(st[0][0], st[1][0]) // range(0, 1);
st[1][1] = f(st[1][0], st[2][0]) // range(1 ,2);
```

## Range Sum Queries

#### Precomputation O(N log N)
```c++
long long st[MAXN][K];

for (int i = 0; i < N; i++)
    st[i][0] = array[i];

for (int j = 1; j <= K; j++)
    for (int i = 0; i + (1 << j) <= N; i++)
        st[i][j] =                       // st[0][2] range(0, 3)
          st[i][j-1] +                   // st[0][1] range(0, 1)
          st[i + (1 << (j - 1))][j - 1]; // st[2][1] range(2, 3)
```

#### Get sum of range O(K) = O(log MAXN)
```
range(L, R) = range(L, L + 2^j - 1) + range(L + 2^j, L + 2^(p) - 1) + ...
range(2, 13) = range(2, 2 + 2^3 - 1) + range(10, 10 + 2^2 - 1)
             = range(2, 9) + range(10, 13)
             = st[2][3] + st[10][2]

range(4, 26) = range(4, 4 + 2^4 - 1) + 
               range(20, 20 + 2^2 - 1) + 
               range(24, 24 + 2^1 - 1) + 
               range(26, 26 + 2^0 - 1)
             = range(4, 19) + 
               range(20, 23) +
               range(24, 25) +
               range(26, 26)
             = st[4][4] + st[20][2] + st[24][1] + st[26][0]
```
```c++
long long sum = 0;
for (int j = K; j >= 0; j--) {
  if ((1 << j) <= R - L + 1) { // R >= L + 2^j - 1
    sum += st[L][j];
    L += 1 << j;
  }
}
```

## Range Minimum Queries

#### Precomputation
```c++
int st[MAXN][K];

for (int i = 0; i < N; i++)
    st[i][0] = array[i];

for (int j = 1; j <= K; j++)
    for (int i = 0; i + (1 << j) <= N; i++)
        st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
```

#### Get Range Minimum

先找 log2 因为每个 range 都可以 divide by 2
```
Eg 2 -> 14 = 13 = (1101)
range(2, 14) = range(2, 9) + range(7, 14)
             = st[2][3] + st[7][3]

|-------------|
          |------------------|
2 3 4 5 6 7 8 9 10 11 12 13 14
```

```c++
int log[MAXN+1];
log[1] = 0;
for (int i = 2; i <= MAXN; i++)
  log[i] = log[i/2] + 1;

int j = log[R - L + 1];
int minimum = min(st[L][j], st[R - (1 << j) + 1][j]);
```

## Range GCD Query

#### Precomputation
```c++
int st[MAXN][K];

for (int i = 0; i < N; i++)
    st[i][0] = array[i];

for (int j = 1; j <= K; j++)
    for (int i = 0; i + (1 << j) <= N; i++)
        st[i][j] = gcd(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
```

#### Get Range GCD
```c++
int log[MAXN+1];
log[1] = 0;
for (int i = 2; i <= MAXN; i++)
  log[i] = log[i/2] + 1;

int j = log[R - L + 1];
int minimum = min(st[L][j], st[R - (1 << j) + 1][j]);
```