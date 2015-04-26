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

int main()
{
	int T; cin>>T;

	rep(i,T)
	{
		int d; cin>>d;

		vector<int> cakes(d,0);
		rep(j,d){ cin>>cakes[j]; }

		int ans = static_cast<int>(1e9);
		int time = 0;

		while(time<ans)
		{
			sort(cakes.begin(), cakes.end(), greater<int>());
			ans = min(ans, cakes[0]+time);

			int n = 0;
			rep(j,d){ if(cakes[j]>3){ ++n; } }

			if(n==0){ break; }

			rep(j,n)
			{
				cakes.push_back(cakes[j]/2);
				cakes[j]-=cakes[cakes.size()-1];
			}

			++time;
		}

		cout<<"Case #"<<(i+1)<<": "<<ans<<endl;
	}

	return 0;
}
