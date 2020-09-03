#include<bits/stdc++.h>
using namespace std;
int main()
{
	for(int T = 1; T <= 1000; ++T)
	{
		system("random.exe");
		double st = clock();
		system("sol.exe");
		double ed = clock();
		system("bf.exe");
		if(system("fc data.out data.ans"))
		{
			puts("Wrong Answer");
			return 0;
		}
		else
		{
			printf("Acceped, test#%d : time =  %0.lfms\n", T, ed - st);
		}
	}
	return 0;
}