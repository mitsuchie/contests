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

bool isOk(char c)
{
    if (c == 'A') { return true; }
    if (c == 'C') { return true; }
    if (c == 'G') { return true; }
    if (c == 'T') { return true; }
    return false;
}

int main()
{
    string s;
    cin >> s;

    const int n = s.size();

    int ans = 0;

    REP(i, 0, n)
    REP(j, i, n)
    {
        bool ok = true;
        REP(k, i, j+1) { if (!isOk(s[k])) { ok = false; } }

        if (ok) { ans = max(ans, j - i + 1); }
    }

    cout << ans << endl;

    return 0;
}
