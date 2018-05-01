#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <complex>
using namespace std;

#define REP(i,p,n) for(int i=p;i<n;++i)
#define rep(i,n) REP(i,0,n)

typedef long long int ll;
typedef pair<int,int> pii;

static constexpr int INF = 100000;

inline double calc(int x, int y) { return static_cast<double>(x * 100) / static_cast<double>(y); }

int solve(int N, int L, const vector<int>& C)
{
    int result = 0;

    int rest = N;
    for(const auto& c : C) { rest -= c; }

    int rounded1 = round(calc(1, N));
    int floored1 = static_cast<int>(calc(1, N));

    if (rounded1 != floored1) // 0.5以上 (常に新しい言語を選んだ方がいいケース)
    {
        for(auto& c : C) { result += round(calc(c, N)); }
        result += rest * rounded1;

        return result;
    }

    // 次に差が発生する人数までの距離
    vector<int> dist(N + 1, INF);

    int previousDiff = 0;

    for(int i=N-1;i>=0;--i)
    {
        // n人が選択したときと、n個の新しい言語を選んだ時との差
        const int currentDiff = round(calc(i, N)) - (rounded1 * i);
        dist[i] = currentDiff == previousDiff ? dist[i + 1] + 1 : 1;

        previousDiff = currentDiff;
    }

    // 次に差が発生する距離が一番小さいやつが先頭に来るようなPriorityQueue
    priority_queue<pii, vector<pii>, greater<pii> > Q;

    rep(i, N)
    {
        const int n = i < C.size() ? C[i] : 0;
        Q.push(pii(dist[n], n));
    }

    while(rest > 0)
    {
        pii head = Q.top();
        Q.pop();

        // とりあえず差が発生するところまで足していく
        const int step = min(rest, head.first);
        rest -= step;

        head.second += step;
        head.first  = dist[head.second];

        Q.push(head);
    }

    rep(i, N)
    {
        const int n = Q.top().second;
        Q.pop();

        result += round(calc(n, N));
    }

    return result;
}

int main()
{
    int t;
    cin>>t;

    rep(i, t)
    {
        int N, L;
        cin>>N>>L;

        vector<int> C(L);
        rep(j, L) { cin>>C[j]; }

        int ans = solve(N, L, C);

        cout<<"Case #"<<(i+1)<<": ";
        cout<<ans<<endl;
    }

    return 0;
}
