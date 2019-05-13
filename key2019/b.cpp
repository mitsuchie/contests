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
    const string key = "keyence";

    string s;
    cin >> s;

    const int n = s.size();

    bool ok = false;

    REP(i, 0, n + 1)
    REP(j, i, n + 1)
    {
        const string ss = s.substr(0, i) + s.substr(j, n);
        ok |= key == ss;

        // cout << "i=" << i << " j=" << j << " " << ss << endl;
    }

    cout << (ok ? "YES" : "NO") << endl;

    return 0;
}
