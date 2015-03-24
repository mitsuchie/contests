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

#define REP(i,p,n) for(ll i=p;i<n;++i)
#define rep(i,n) REP(i,0,n)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vint;
typedef vector<pii> vpii;
typedef vector<vint> det1;
typedef vector<vpii> det2;

int main()
{
	map<ll,ll> nums;

	ll a,b;
	cin>>a>>b;

	REP(i,b+1,a+1)
	{
		ll n = i;
		for(ll j=2;j*j<=n;++j)
		{
			ll sum = 0;
			while((n%j)==0){ ++sum; n/=j; }
			nums[j] += sum;
		}

		if(n!=1){ ++nums[n]; }
	}

	ll ans = 1;
	ll mod = ll(1e9) + 7LL;

	for(map<ll,ll>::iterator it=nums.begin(),end=nums.end();it!=end;++it)
	{
		ans *= (*it).second + 1;
		ans %= mod;
	}

	cout<<ans<<endl;

	return 0;
}
