#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T> inline T random(T R){return (double)rand() / RAND_MAX * R + ((T)0.5 == 0 ? 0.5 : 0.0);}
template<typename T> inline T random(T L, T R){return random(R - L) + L;}
string get_string(int len)
{
	string res;
	char s[] = {'A', 'C', 'T', 'G'};
	for(int i = 1; i <= len; ++i)
	{
		res.push_back(s[random(0, 3)]);
	}
	return res;
}
int main()
{
	srand((unsigned) time(0));
	freopen("data.in", "w", stdout);
	int T = 3;
	while(T --)
	{
		ll n = random(3 ,15);
		printf("%lld\n", n);
		for(int i = 1; i <= n; ++ i) printf("%d ", random((int)100));
		puts("");
	}
	puts("0");
	//out.close();
	return 0;
}