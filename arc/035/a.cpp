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
	string s;
	cin>>s;

	bool ok = true;

	rep(i,s.size())
	{
		if( s[i] == s[s.size()-1-i] ){ continue; }
		if( s[i] == '*' ){ continue; }
		if( s[s.size()-1-i] == '*' ){ continue; }

		ok = false;
	}

	cout<<(ok?"YES":"NO")<<endl;

	return 0;
}
