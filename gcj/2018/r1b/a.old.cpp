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

typedef priority_queue<pii> pq;

int INF = 100000;

int solve(int N, int L, vector<int>& C)
{
    int res = 0;

    int last = N;
    rep(i, C.size()) { last -= C[i]; }

    int one = round(100.0 / static_cast<double>(N));
    int two = static_cast<int>(100.0 / static_cast<double>(N));
    // printf("one=%d, two=%d\n", one, two);

    if (one != two)
    {
        rep(i, C.size()) { res += round(static_cast<double>(100 * C[i]) / static_cast<double>(N)); }
        res += last * one;

        return res;
    }

    vector<int> over(N + 1);
    vector<int> dist(N + 1);

    rep(i, N + 1)
    {
        const int index = N - i;

        const auto lhs = static_cast<double>(index);
        const auto rhs = static_cast<double>(N);
        const auto cur = 100.0 * lhs / rhs;
        const auto mor = one * index;

        over[index] = round(cur) - mor;
        dist[index] = index == N ? INF
                                 : (over[index + 1] == over[index] ? dist[index + 1] + 1 : 1);

        // printf("%d: cur=%f, %d - %d = %d, dist=%d\n", index, cur, (int)round(cur), mor, over[index], dist[index]);
    }

    priority_queue<pii, vector<pii>, greater<pii> > Q;

    rep(i, N)
    {
        int num = i < C.size() ? C[i] : 0;
        Q.push(pii(dist[num], num));
    }

    while(last > 0)
    {
        pii head = Q.top(); Q.pop();

        // printf("last=%d: ", last);
        // rep(i, N) { printf("%d ", nums[i].second); } printf("\n");

        int step = min(last, head.first);
        last -= step;

        head.second += step;
        head.first  = dist[head.second];

        Q.push(head);
    }

    rep(i, N)
    {
        const int num = Q.top().second; Q.pop();
        res += one * num;
        res += over[num];
    }

    return res;
}

int main()
{
    int t;
    cin>>t;

    rep(i, t)
    {
        int N, L;
        cin>>N>>L;

        vector<int> C;
        C.assign(L, 0);
        rep(j, L) { cin>>C[j]; }

        int ans = solve(N, L, C);

        cout<<"Case #"<<(i+1)<<": ";
        cout<<ans<<endl;
    }

    return 0;
}
