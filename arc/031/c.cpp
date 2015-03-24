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

const int MAXN=101;
int N;
vint B;

int main()
{
	cin>>N;
	B.assign(N,0); rep(i,N){ cin>>B[i]; }

	vint sorted(B);
	sort(sorted.begin(),sorted.end());

	int ans = 0, tmp = 0, l = 0, r = 0;

	rep(i,N)
	{
		int index = find(B.begin(),B.end(),sorted[i]) - B.begin();

		bool left = abs(index-l) < abs(N-r-index-1);
		if(index==(N/2)){ left = (B[l]>B[N-r-1]); }

		cout<<"index="<<index<<", left="<<left<<endl;
		rep(j,N){ cout<<B[j]<<" "; } cout<<endl;

		if(left)
		{
			int n = index - l - 1;
			rep(j,n){ swap(B[index-j],B[index-j-1]); ++ans; }
			++l;
		}
		else
		{
			int n = N - index - r - 1;
			rep(j,n){ swap(B[index+j],B[index+j+1]); ++ans; }
			++r;
		}

		rep(j,N){ cout<<B[j]<<" "; } cout<<endl;
		cout<<"ans="<<ans<<endl;
	}

	cout<<ans<<endl;

	return 0;
}
