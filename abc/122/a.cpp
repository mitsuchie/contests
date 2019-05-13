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
    char c;
    cin >> c;

    if (c == 'A') { cout << 'T' << endl; }
    if (c == 'C') { cout << 'G' << endl; }
    if (c == 'G') { cout << 'C' << endl; }
    if (c == 'T') { cout << 'A' << endl; }

    return 0;
}
