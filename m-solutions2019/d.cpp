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
#include <tuple>
using namespace std;

#define REP(i,p,n) for(int i=p;i<n;++i)
#define rep(i,n) REP(i,0,n)

using ll = long long int;
using pll = pair<ll, ll>;

int N;

const int MAXN = 100000;
ll A[MAXN], B[MAXN], C[MAXN];

ll R[MAXN];
vector<ll> G[MAXN];

ll CC[MAXN];

int main()
{
    cin >> N;

    ll max_rv = 0;
    ll max_ri = -1;

    rep(i, N - 1)
    {
        ll a, b;
        cin >> a >> b;
        --a;
        --b;

        ++R[a];
        ++R[b];

        if (R[a] >= max_rv)
        {
            max_rv = R[a];
            max_ri = a;
        }

        if (R[b] >= max_rv)
        {
            max_rv = R[b];
            max_ri = b;
        }

        G[a].push_back(b);
        G[b].push_back(a);

        A[i] = a;
        B[i] = b;
    }

    rep(i, N)
    {
        cin >> C[i];
    }

    sort(C, C + N);
    reverse(C, C + N);

    fill(CC, CC + N, -1);

    priority_queue<pll> Q;
    Q.push(pll(max_rv, max_ri));

    ll ci = 0;

    while (!Q.empty())
    {
        const auto p = Q.top(); Q.pop();

        const auto value = p.first;
        const auto index = p.second;

        // cout << "index=" << index << ", value=" << value << ", C=" << C[ci] << endl;

        CC[index] = C[ci];
        ++ci;

        for (const auto nextIndex : G[index])
        {
            if (CC[nextIndex] != -1) { continue; }
            Q.push(pll(R[nextIndex], nextIndex));
        }
    }

    ll ans = 0;

    rep (i, N - 1)
    {
        const auto ca = CC[A[i]];
        const auto cb = CC[B[i]];

        ans += min(ca, cb);
    }

    // cout << "ans=" << ans << endl;
    cout << ans << endl;

    rep (i, N)
    {
        cout << CC[i] << endl;
    }

    return 0;
}
