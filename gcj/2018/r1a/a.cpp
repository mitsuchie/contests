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

int R, C, H, V;
vector<string> W;

void input()
{
    cin >> R >> C >> H >> V;

    W.clear();

    rep(y, R)
    {
        string s;
        cin>>s;
        W.push_back(s);
    }
}

bool solve()
{
    input();

    rep(i, R - 1)
    rep(j, C - 1)
    {
        int nums[] = { 0, 0, 0, 0 };

        rep(y, R)
        rep(x, C)
        {
            if (W[y][x] != '@') { continue; }

            if (y <  i + 1 && x <  j + 1) { ++nums[0]; }
            if (y >= i + 1 && x <  j + 1) { ++nums[1]; }
            if (y <  i + 1 && x >= j + 1) { ++nums[2]; }
            if (y >= i + 1 && x >= j + 1) { ++nums[3]; }
        }

        bool ok = true;
        rep(t, 4) if (nums[0] != nums[t]) { ok = false; }

        if (ok) { return true; }
    }

    return false;
}

int main()
{
    int t;
    cin>>t;

    rep(i, t)
    {
        bool res = solve();
        cout<<"Case #"<<(i + 1)<<": "<<(res ? "POSSIBLE" : "IMPOSSIBLE")<<endl;
    }

    return 0;
}
