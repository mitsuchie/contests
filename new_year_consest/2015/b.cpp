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

int N;
vector<int> W;

int main()
{
	cin>>N;

	W.assign(N,0);
	rep(i,N){ cin>>W[i]; }

	sort(W.begin(),W.end());

	int ans = 0, w = 0;
	rep(i,N){ if(w<W[i]){ w+=W[i]; ++ans; } }

	cout<<ans<<endl;

	return 0;
}
