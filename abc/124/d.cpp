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

int N, K;
string S;

int main()
{
    cin >> N >> K >> S;
    N = S.size();

    vector<int> lens;

    if (S[0] == '0') { lens.push_back(0); }

    int len = 0;

    for (int i=0;i<N;++i)
    {
        if (i - 1 >= 0 && S[i] != S[i - 1])
        {
            lens.push_back(len);
            len = 0;
        }

        ++len;
    }

    lens.push_back(len);

    lens.push_back(0);
    lens.push_back(0);
    lens.push_back(0);
    lens.push_back(0);

    int value = lens.size() >= 0 ? lens[0] : 0;

    const int length = min<int>(lens.size() / 2, K);

    for (int i=0;i<length;++i)
    {
        value += lens[i * 2 + 1] + lens[i * 2 + 2];
    }

    int ans = value;

    for (int i=0;(i+length+1)*2+1<lens.size();++i)
    {
        const int p = i;
        const int q = i + length;

        const int pp = lens[p * 2] + lens[p * 2 + 1];
        const int qq = lens[q * 2 + 1] + lens[q * 2 + 2];

        const int nextValue = value - pp + qq;

        value = nextValue;

        ans = max<int>(ans, value);
    }

    cout << ans << endl;

    return 0;
}
