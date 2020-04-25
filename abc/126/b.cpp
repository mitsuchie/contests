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

using ll = long long int;
using pll = pair<ll, ll>;

int main()
{
    string s;
    cin >> s;

    const int a = (s[0] - '0') * 10 + (s[1] - '0');
    const int b = (s[2] - '0') * 10 + (s[3] - '0');

    if (a == 0 && b == 0) { cout << "NA" << endl; }
    else if (a == 0 && b <= 12) { cout << "YYMM" << endl; }
    else if (b == 0 && a <= 12) { cout << "MMYY" << endl; }
    else if (b == 0 || a == 0) { cout << "NA" << endl; }
    else if (a <= 12 && b <= 12) { cout << "AMBIGUOUS" << endl; }
    else if (a <= 12 && b >  12) { cout << "MMYY" << endl; }
    else if (a >  12 && b <= 12) { cout << "YYMM" << endl; }
    else { cout << "NA" << endl; }

    return 0;
}
