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

int X,R,C;

const int dir[] = { 1, -1, 1, -1, 1 };

int count_connects(det1& det,int x,int y,int v)
{
	if(x<0||R<=x||y<0||C<=y){ return 0; }
	if(det[x][y]!=v){ return 0; }

	det[x][y] = 1 - v;

	int res = 1;
	rep(i,4){ res += count_connects(det,x+dir[i],y+dir[i+1],v); }

	return res;
}

bool color(det1& det,int d,int x,int y)
{
	if( d == X )
	{
		det1 tmp1(det);
		det1 tmp2(det);

		bool ok1 = false;
		rep(xx,R) rep(yy,C) ok1 |= count_connects(tmp1,x,y,1) == X;

		if(!ok1){ return true; }

		bool ok2 = true;
		rep(xx,R) rep(yy,C) ok2 &= (count_connects(tmp2,x,y,0) % X) == 0;

		return ok2;
	}

	bool res = true;

	REP(xx,x+1,R) REP(yy,y,C)
	{
		det[xx][yy] = 1;

		res &= color(det, d+1, xx, yy);

		det[xx][yy] = 0;
	}

	return res;
}

bool solve()
{
	cin>>X>>R>>C;
	if(R*R<X || C*C<X || R*C < X){ return false; }

	det1 det(R,vint(C,0));
	return color(det,0,-1,0);
}

int main()
{
	int T; cin>>T;
	rep(i,T){ cout<<"Case #"<<i+1<<": "<<(solve()?"GABRIEL":"RICHARD")<<endl; }

	return 0;
}
