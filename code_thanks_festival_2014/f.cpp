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

int N,M;

int main()
{
	cin>>N>>M;

	vint ans;
	rep(i,N){ ans.push_back(i); }

	vpii ab(M,pii(0,0));
	rep(i,M){ cin>>ab[i].first>>ab[i].second; }

	int tmp = 0;

	bool ok = true;
	while(ok)
	{
		ok = false;

		rep(i,M)
		{
			vint::iterator a = find(ans.begin(),ans.end(),ab[i].first-1);
			vint::iterator b = find(ans.begin(),ans.end(),ab[i].second-1);

			if(a>b){ tmp=*a; *a=*b; *b=tmp; ok = true; }
		}

		// rep(i,N){ cout<<ans[i]<<" "; } cout<<endl;
	}

	int n = (find(ans.begin(),ans.end(),0) - ans.begin());
	// cout<<"n="<<n<<endl;

	ok = true;
	while(ok&&n!=0)
	{
		tmp = ans[n];
		ans[n] = ans[n-1];
		ans[n-1] = tmp;

		rep(i,M)
		{
			vint::iterator a = find(ans.begin(),ans.end(),ab[i].first-1);
			vint::iterator b = find(ans.begin(),ans.end(),ab[i].second-1);

			if(a>b){ tmp=*a; *a=*b; *b=tmp; ok = false; }
		}

		if(ok){ --n; }

		// rep(i,N){ cout<<ans[i]<<" "; } cout<<endl;
	}

	cout<<n+1<<endl;

	return 0;
}
