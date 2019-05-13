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

const int MAXN = 128;
int C;
int B[MAXN];
int B1[MAXN], B2[MAXN];

int LEVEL;

bool solve()
{
    LEVEL = 0;

    rep(i, C) { B1[i] = 1; B2[i] = 0; }

    rep(i, C) if (B[i])
    {
        int k = B[i];
        rep(j, C) if (k > 0 && B1[j])
        {
            --k;
            B1[j] = 0;
            B2[j] = i == j ? 0 : (i < j ? -1 : 1);

            LEVEL = max(abs(i - j), LEVEL);
        }

        if (k > 0) { return false; }
    }

    rep(i, C) if (B1[i]) { return false; }

    return true;
}

int main()
{
    int t;
    cin>>t;

    rep(i, t)
    {
        cin>>C;
        rep(j, C) { cin>>B[j]; }

        auto ans = B[0] != 0 && B[C-1] != 0 && solve();

        if (ans)
        {
            cout<<"Case #"<<(i+1)<<": "<<LEVEL<<endl;

            rep(k, LEVEL)
            {
                rep(j, C) { cout<<(B2[j] == 0 ? '.' : (B2[j] < 0 ? '/' : '\\')); }
                cout<<endl;
            }
            rep(j, C) { cout<<"."; } cout<<endl;
        }
        else
        {
            cout<<"Case #"<<(i+1)<<": IMPOSSIBLE"<<endl;
        }
    }

    return 0;
}

