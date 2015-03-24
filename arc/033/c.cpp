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
	const int MAXN=200002;
	const int SQRT_MAXN=448;
	vector<vint> nums(SQRT_MAXN,vint());

	int n;
	cin>>n;

	rep(i,n)
	{
		int t, x;
		cin>>t>>x;

		if(t==1)
		{
			vint& v = nums[sqrt(x)];

			rep(j,v.size()){ if(x<v[j]){ v.insert(v.begin()+j,x); break; } }
			if(v.empty()){ v.push_back(x); }
		}
		else
		{
			--x;

			vector<vint>::iterator it = nums.begin(), end = nums.end();

			int sum=0;
			for(;it!=end&&sum+(*it).size()<=x;++it){ sum += (*it).size();}


			cout<<(*it)[x-sum]<<endl;
			(*it).erase((*it).begin()+(x-sum));
		}
	}

	return 0;
}
