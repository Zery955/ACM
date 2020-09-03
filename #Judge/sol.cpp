
#include <iostream>
#include <stack>
#include <list>
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
ll sumi(ll n){return (1LL + n) * n / 2;}
ll sumi2(ll n) {return (n + 1) * n * (n * 2 + 1) / 6;}
ll ksm(ll a, ll k, ll Mod){ll res = 1; while(k){if(k & 1) (res *= a) %= Mod; (a *= a) %= Mod; k >>= 1;} return res % Mod;}
inline ll inv(ll a, ll Mod){return ksm(a, Mod - 2, Mod);}
inline void cap_bit(ll x){ for(int i = 63; i >= 0; --i)if(x >> i & 1) {printf("Need (%d) = %lld\n", i + 1, 1LL << (i + 1)); return;}}
inline void cal_space(ll x){printf("%lld MB\n" ,x >> 20);}
const int dx[] = {1, -1, 0, 0, 0, 0};
const int dy[] = {0, 0, 1, -1, 0, 0};
const int dz[] = {0, 0, 0, 0, 1, -1};
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
#define mem(x) memset(x, 0, sizeof x)
const int N = 1e6 + 5;
const int M = 35;
ll Mod =  1e9 + 7; 
const ll INF = 1e16;
ll INV2 = inv(2, Mod);
template<typename T>inline void addmod(T &a, T b){a += b; if(a >= Mod) a -= Mod;}
template<typename T>inline void submod(T &a, T b){a -= b; if(a < 0) a += Mod;}
//************************************
int idu[N];
namespace Splay{
	const int N = 1e6 + 5;
	typedef long long ll;
	const ll INF = 1e17;
	ll* a; int n;
	int rt, np;
	struct node{
		int ch[2];int fa;ll val;
		int cnt;int sz;
		ll sum, tmin;
		ll tag_sum;int tag_reverse;
	}t[N];
	void newp(int ls, int rs, int fa, ll val, int cnt, int sz, ll sum, ll tmin, ll tag_sum, int tag_reverse)
	{
		++ np;
		t[np].ch[0] = ls; t[np].ch[1] = rs; t[np].fa = fa; t[np].val = val;
		t[np].cnt = cnt; t[np].sz = sz;
		t[np].sum = sum;
		t[np].tag_sum = tag_sum; t[np].tmin = tmin; t[np].tag_reverse = tag_reverse;
	}
	inline void push_up(int u)
	{
		
		t[u].sz = t[u].cnt;
		t[u].sum = t[u].val;
		t[u].tmin = t[u].val;
		if(t[u].ch[0])
		{
			t[u].sz += t[t[u].ch[0]].sz;
			t[u].sum += t[t[u].ch[0]].sum; 
			t[u].tmin = min(t[u].tmin, t[t[u].ch[0]].tmin);
		}
		if(t[u].ch[1])
		{
			t[u].sz += t[t[u].ch[1]].sz;
			t[u].sum += t[t[u].ch[1]].sum;
			t[u].tmin = min(t[u].tmin, t[t[u].ch[1]].tmin);
		}
	}
	inline void mark_add(int u, ll val)
	{
		t[u].tag_sum += val;
		t[u].val += val;
		t[u].sum += val * t[u].sz;
		t[u].tmin += val;
	}
	inline void mark_reverse(int u)
	{
		t[u].tag_reverse ^= 1;
		swap(t[u].ch[0], t[u].ch[1]);
	}
	inline void push_down(int u)
	{
		/* **** 标记下传 ****/
		if(u && t[u].tag_sum)
		{
			mark_add(t[u].ch[0], t[u].tag_sum);
			mark_add(t[u].ch[1], t[u].tag_sum);
			t[u].tag_sum = 0;
		}
		if(u && t[u].tag_reverse)
		{
			mark_reverse(t[u].ch[0]);
			mark_reverse(t[u].ch[1]);
			t[u].tag_reverse = 0;
		}
	}
	void push_down_from_rt(int u)
	{
		if(u == 0) return;
		push_down_from_rt(t[u].fa);
		push_down(u);
	}
	inline bool get(int x){return x == t[t[x].fa].ch[1];}
	inline void rotate(int x)
	{
		int y = t[x].fa, z = t[y].fa, son = get(x);
		t[y].ch[son] = t[x].ch[son ^ 1];
		t[t[x].ch[son ^ 1]].fa = y;
		t[x].ch[son ^ 1] = y;
		t[y].fa = x;
		t[x].fa = z;
		if(z) t[z].ch[y == t[z].ch[1]] = x;
		push_up(y);
		push_up(x);
	}
	void splay(int u, int v = 0)
	{
		for(int f = t[u].fa; (f = t[u].fa) != v; rotate(u))
		{
			if(t[f].fa != v) rotate(get(u) == get(f) ? f : u);
		}
		if(v == 0) rt = u;
	}
	int build(int l, int r, int fa) //记得赋值根
	{
		if(l > r) return 0;
		int mid = l + r >> 1;
		//***** 新建节点 *****
		newp(0, 0, fa, a[mid - 1], 1, 1, a[mid - 1], a[mid - 1], 0, 0);
		int cur = np;
		if(a[mid - 1] != INF) idu[a[mid - 1]] = cur;
		t[cur].ch[0] = build(l, mid - 1, cur);
		t[cur].ch[1] = build(mid + 1, r, cur);
		
		push_up(cur);
		//*********************
		return cur;
	}
	int kth(ll x) // 查找中序第x个数
	{
		int u = rt;
		while(1)
		{
			push_down(u);
			if(x <= t[t[u].ch[0]].sz) u = t[u].ch[0];
			else
			{
				x -= t[t[u].ch[0]].sz + 1;
				if(x == 0) return u;
				u = t[u].ch[1];
			}
		}
	}
	inline void make(int &l, int &r)
	{
		l = kth(l + 1); r = kth(r + 1);
		splay(l, 0);
		splay(r, l);
	}
	void section_add(int x, int y, ll val)
	{
		int l = x - 1, r = y + 1;
		make(l, r);
		int u = t[rt].ch[1];
		u = t[u].ch[0];
		mark_add(u, val);
	}
	void section_reverse(int x, int y)
	{
		int l = x - 1, r = y + 1;
		make(l, r);
		int u = t[rt].ch[1];
		u = t[u].ch[0];
		mark_reverse(u);
	}
	void section_revolve(int x, int y, ll dt)
	{
		int len = y - x + 1;
		dt %= len;
		if(dt == 0) return;
		dt = len - dt;// 向右循环移位
		section_reverse(x + dt, y);
		section_reverse(x, y);
		section_reverse(y - dt + 1, y);
	}
	void insert(int pos, ll val) // 在位置pos后面插入val
	{
		int l = pos, r = pos + 1;
		make(l, r);
		newp(0, 0, r, val, 1, 1, val, val, 0, 0);
		int u = t[rt].ch[1];
		t[u].ch[0] = np;
		push_up(r);
		push_up(l);
	}
	void erase(int pos)// 删除位置第pos个元素
	{
		int l = pos - 1, r = pos + 1;
		make(l, r);
		t[r].ch[0] = 0;
		push_up(r);
		push_up(l);
	}
	ll query_min(int x, int y)
	{
		int l = x - 1, r = y + 1;
		make(l, r);
		int u = t[rt].ch[1];
		u = t[u].ch[0];
		return t[u].tmin;
	}
	ll query_sum(int x, int y)
	{
		int l = x - 1, r = y + 1;
		make(l, r);
		int u = t[rt].ch[1];
		u = t[u].ch[0];
		return t[u].sum;
	}
	void print(int u = rt)
	{
		if(u == 0) return;
		push_down(u);
		print(t[u].ch[0]);
		if(t[u].val != INF)printf("%d ", t[u].val);
		print(t[u].ch[1]);
	}
	void init(ll* _a, int _n) // a为被维护序列[1···N]
	{
		a = _a;
		n = _n;
		a[0] = a[n + 1] = INF;
		np = 0;
		rt = Splay :: build(1, n + 2, 0);
	}
	/**** 使用手册 ****
	# 初始化直接调用 init() 即可完成建树
	# 调用 modify修改
	# 调用 query询问
	*/
	int cal(int x)
	{
		push_down_from_rt(idu[x]);
		splay(idu[x]);
		return t[t[rt].ch[0]].sz;
	}
}
ll a[N], bucket[N], n;
vector<ll> nums;
int main()
{	
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	while(scanf("%lld", &n)!= EOF && n)
	{
		for(int i = 1; i <= n; ++ i) bucket[i] = 0;
		nums.clear();
		for(int i = 1; i <= n; ++ i)
		{
			read(a[i]);
			nums.pb(a[i]);
		}
		sort(all(nums));
		nums.erase(unique(all(nums)), nums.end());
		for(int i = n; i >= 1; -- i) 
		{	
			a[i] = lower_bound(all(nums), a[i]) - nums.begin() + 1;
			bucket[a[i]] ++ ;
		}
		for(int i = 1; i <= n; ++ i) bucket[i] += bucket[i - 1];
		for(int i = n; i >= 1; -- i) a[i] = bucket[a[i]] --;
		Splay :: init(a, n);
		for(int i = 1; i <= n; ++ i)
		{
			int pos = Splay :: cal(i);
			Splay :: section_reverse(i, pos);
			printf("%d ", pos);
		}
		br;
	}
    return 0;
}