#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <string>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define REP(i,p,n) for(int i=p;i<n;++i)
#define rep(i,n) REP(i,0,n)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vint;
typedef vector<pii> vpii;
typedef vector<vint> det1;
typedef vector<vpii> det2;

int N,K;
vint PS;

int count_empties(int s)
{
	vint sheets(K+2,0);
	int aa = 0, bb = 0;

	rep(i,N)
	{
		if(((s>>i)&1) == 0) // ‚Æ‚É‚©‚­
		{
			aa = 0;
			while(aa<K && sheets[aa+1]==1){ ++aa; }
			if(aa<K){ sheets[aa+1]=1; }// else { return false; }
		}
		else // —]—T‚ ‚è
		{
			bb = 0;
			while(bb<K && (sheets[bb+1]==1||sheets[bb]==1||sheets[bb+2]==1)){ ++bb; }
			if(bb<K){ sheets[bb+1]=1; }// else { return false; }
		}
	}

	// rep(i,K+2){ cout<<sheets[i]<<","; } cout<<endl;
	sheets[0]   = 1;
	sheets[K+1] = 1;

	return count(sheets.begin(),sheets.end(),0);
}

int main()
{
	cin>>N>>K;
	if(N>=11){ cout<<"invalid"<<endl; return 0; }

	PS.assign(N,0);
	rep(i,N){ cin>>PS[i]; }

	double ans = 0.0;

	rep(i,1<<N)
	{
		double rate = double(count_empties(i));
		rep(j,N){ rate *= ((i>>j)&1? double(100-PS[j]) : double(PS[j])) / 100.0; }
		ans += rate;
	}

	printf("%.06f\n",ans);

	return 0;
}
