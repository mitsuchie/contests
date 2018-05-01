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

const int I = 2;
const int J = 3;
const int K = 4;

const int MAXN=10001;
int s[MAXN];

const int mat[5][5] = {
	{ 0, 0, 0, 0, 0 },
	{ 1,  I, J, K, 0 },
	{ I, -1, K, -J, 0 },
	{ J, -K, -1, I, 0 },
	{ K, J, -I, -1, 0 },
};

int add(int prev, int next)
{
	const int a = abs(prev);
	const int b = abs(next);

	return mat[a][b] * (mat[a][b]*prev*next<0?-1:1);
}

int remove(int prev,int next)
{
	const int a = abs(prev);
	const int b = abs(next);

	if(mat[a][1] == next){ return 1; }
	if(mat[a][I] == next){ return I; }
	if(mat[a][J] == next){ return J; }
	if(mat[a][K] == next){ return K; }

	return 0;
}

int reduce(int lhs,int rhs)
{
	int sign = 1;
	int res  = 1;
	REP(i,lhs,rhs)
	{
	}

	return sign * res;
}

bool solve()
{
	int L,X;
	string S;
	cin>>L>>X>>S;

	rep(i,MAXN){ s[i]=0; }

	int index = 0;
	rep(i,X) rep(j,L)
	{
		if(S[j] == 'i'){ s[index] = I; }
		if(S[j] == 'j'){ s[index] = J; }
		if(S[j] == 'k'){ s[index] = K; }

		++index;
	}

	const int n = L*X;
	if(n<=2){ return false; }

	cout<<n<<endl;

	REP(i,1,n)
	REP(j,i,n)
	{
		if(i-0<1){ continue; }
		if(j-i<1){ continue; }
		if(n-j<1){ continue; }

		const int a = reduce(0,i);
		const int b = reduce(i,j);
		const int c = reduce(j,n);

		const int sign = a * b * c;
		if(sign < 0){ continue; }

		const int aa = a<0 ? -a : a;
		const int bb = b<0 ? -b : b;
		const int cc = c<0 ? -c : c;

		if( aa == I && bb == J && cc == K ){ return true; }
	}

	return false;
}

int main()
{
	int T; cin>>T;
	rep(i,T){ cout<<"Case #"<<i+1<<": "<<(solve()?"YES":"NO")<<endl; }

	return 0;
}
