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
    int N;
    cin >> N;

    string s;
    cin >> s;

    int num = 0;
    rep(i, s.size()) { num += (s[i] == 'R' ? 1 : -1); }

    cout << (num >= 1 ? "Yes" : "No") << endl;

    return 0;
}
