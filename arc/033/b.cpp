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

// const int MAXN=100000;
// bool used[MAXN];
map<int,int> used;

int main()
{
	int na, nb, id;
	cin>>na>>nb;

	int lhs = 0, rhs = 0;
	rep(i,na){ cin>>id; used[id-1] = 1; }
	rep(i,nb){ cin>>id; if(used[id-1]){ ++lhs; } used[id-1] = 1; }
	rhs = used.size();

	double ans = static_cast<double>(lhs) / static_cast<double>(rhs);

	printf("%.07f\n",ans);

	return 0;
}
