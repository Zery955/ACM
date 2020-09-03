---

<center>E. Inversion SwapSort</center>

**题意：**

​		给定一个有 $n$ 个元素的序列 $A$ 构造一个 $Pair<int,int>$ 数组 $B$ 满足一下条件：

- $B$ 中元素两两不同
- $A$ 中的所有逆元组的下标构成的 $(u, v),u<v,a_u>a_v$ 都在 $B$ 中
- 按照 $B$ 数组的顺序调换顺序：$swap(A_{u_0},A_{v_0}),swap(A_{u_1},A_{v_1})\cdots$ 最终能使的 $A$ 数组变成不下降的数组。

**题解：**

​		对于存在逆元的问题，我们首先考虑弱化的版本：把 $A$ 数组先当成某个关于 $n$ 的一个排列。

​		记 $pos[i]$ 表示 $A$ 中值为  $i$ 的元素所在的位置。

​		我们从后往前遍历逆元，先遍历逆元组第二个元素为 $n$ 的逆元：$(pos_{a_{n+1}},n),\cdots，(pos_n,n)$	

​		自行模拟可以发现最后一个元素变成了 $n$ 前面所有比原先 $A[n]$ 大的数都减少了 $1$ 可以发现逆元的分布是等价的。

​		如$[4,5,2,1,3]->[3,4,2,1,5]$。

​		现在考虑不是排列的问题，发现相等时的换不换无所谓，直接离散化就行，问题直接转化成排列上的问题。

**代码：**

```c++
#include <iostream>
#include <stack>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <set>
using namespace std;
//************************************
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<double, double> pdd;
typedef bitset<100> BIT;
const double eps = 1e-10;
template<typename T> void read(T &x){
    int f = 1;x = 0;char s = getchar();
    while(s < '0'|| s > '9'){if(s == '-') f = -1; s = getchar();}
    while(s >= '0' && s <= '9'){x = x * 10 + s - '0'; s = getchar();}
    x *= f;
}
template<typename T> void print(T x){
    if(x < 0)putchar('-'),x = -x;
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
template<typename T> void println(T x){
    if(x < 0)putchar('-'),x = -x;
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
	putchar('\n');
}
template<typename T, typename ... Args> void read(T &x, Args& ... args){read(x);read(args ...);} 
inline void reads(char *a){scanf("%s", a);}
template<typename ... Args>void reads(char* a, Args* ... args){scanf("%s", a); reads(args...);}
template<typename T, typename ... Args>void print(T x, Args ... args){print(x); putchar(' '); print(args...);}
template<typename T, typename ... Args> void println(T x, Args ... args){print(x); putchar(' '); println(args...);}
inline void prints(char *a){printf("%s", a);}
template<typename T> inline T sqr(T x){return x * x;}
template<typename T> inline T random(T R){return (double)rand() / RAND_MAX * R + ((T)0.5 == 0 ? 0.5 : 0.0);}
template<typename T> inline T random(T L, T R){return random(R - L) + L;}
ll ksm(ll a, ll k, ll Mod){ll res = 1; while(k){if(k & 1) (res *= a) %= Mod; (a *= a) %= Mod; k >>= 1;} return res % Mod;}
inline ll inv(ll a, ll Mod){return ksm(a, Mod - 2, Mod);}
inline void cap_bit(ll x){ for(int i = 63; i >= 0; --i)if(x >> i & 1) {printf("Need (%d) = %lld\n", i + 1, 1LL << (i + 1)); return;}}
inline void cal_space(ll x){printf("%lld MB\n" ,x >> 20);}
const int dx4[] = {0, 0, -1, 1};
const int dy4[] = {-1, 1, 0, 0};
const int dx6[] = {1, -1, 0, 0, 0, 0};
const int dy6[] = {0, 0, 1, -1, 0, 0};
const int dz6[] = {0, 0, 0, 0, 1, -1};
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define nbsp putchar(' ')
#define br puts("")
#define pi acos(-1.0)
#define gcd(x, y) __gcd(x, y)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define xx first
#define yy second
#define lowbit(x) (x) & (-x)
const int N = 3e5 + 1;
const int M = 26;
const ll Mod = 1e9 + 7;
const ll INF = 1e16;	
//************************************
int n;
int a[N];
vector<pii> ans;
map<int, int> mp;
int pos[N];
int main()
{
	cin >> n;
	for(int i = 1; i <= n; ++ i)
	{
		cin >> a[i];
		mp[a[i]] ++ ;//桶排序
	}
	for(auto it = next(mp.begin()); it != mp.end(); ++ it)//前缀和
	{
		it->second += prev(it)->second;
	}
	for(int i = 1; i <= n; ++ i)
	{
		a[i] = mp[a[i]] --;//求离散化后的值
		pos[a[i]] = i;
	}
	for(int i = n; i >= 1; -- i)
		for(int j = a[i] + 1; j <= n; ++ j) if(pos[j] < i)
			ans.pb({pos[j], i});
	cout << ans.size() << endl;
	for(auto i : ans) println(i.xx, i.yy);
    return 0;
}

```

​		

**时间复杂度：** $O(n^2)$

---



 

