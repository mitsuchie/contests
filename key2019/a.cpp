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
    int ins[4];
    rep(i, 4) { cin >> ins[i]; }

    sort(ins, ins + 4);

    const bool ok = ins[0] == 1 && ins[1] == 4 && ins[2] == 7 && ins[3] == 9;
    cout << (ok ? "YES" : "NO") << endl;

    return 0;
}
