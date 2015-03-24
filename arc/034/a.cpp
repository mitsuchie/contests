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
	int n;
	cin>>n;

	int ans = 0;

	rep(i,n)
	{
		int a,b,c,d,e;
		cin>>a>>b>>c>>d>>e;

		int score = (a + b + c + d)*900 + (e*110);
		if(ans<score){ ans = score; }
	}
	
	printf("%.07f\n",static_cast<double>(ans)/900.0);

	return 0;
}
