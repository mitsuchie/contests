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

const int MAXRC = 64;
int G[MAXRC][MAXRC];

const int MAXN = 5001;
int S[MAXN][4];

int R,C,M,N;

int main()
{
	cin>>R>>C>>M>>N;
	rep(i,N){ cin>>S[i][0]>>S[i][1]>>S[i][2]>>S[i][3]; }

	rep(i,N)
	{
		rep(y,R){ rep(x,C){ G[y][x] = 0; } }

		rep(j,N) if(i!=j)
		{
			for(int y=S[j][0]-1,yn=S[j][1]-1;y<=yn;++y)
			for(int x=S[j][2]-1,xn=S[j][3]-1;x<=xn;++x)
			{
				++G[y][x];
			}
		}

		int m = 0;
		rep(y,R){ rep(x,C){ if(G[y][x]%4==0){ ++m; } } }

		// cout<<"m="<<m<<endl;
		if(m == M){ cout<<i+1<<endl; }
	}

	return 0;
}
