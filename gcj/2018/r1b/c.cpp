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

const int MAXN = 128;
int M, R1[MAXN], R2[MAXN], G[MAXN];

bool merge(const vector<int>& tree, int index)
{
    if (tree[index] == -1) { return false; }

    const int lhs = index * 2 + 0;
    const int rhs = index * 2 + 1;

    const int ln = tree[lhs] != -1 ? G[tree[lhs]] : 0;
    const int rn = tree[rhs] != -1 ? G[tree[rhs]] : 0;

    const int num = min(ln, rn);

    if (num != 0) // generatable
    {
        G[tree[lhs]] -= num;
        G[tree[rhs]] -= num;
        G[tree[index]] += num;

        return true;
    }

    if (tree[lhs] != -1 && ln == 0) { return merge(tree, lhs); }
    if (tree[rhs] != -1 && rn == 0) { return merge(tree, rhs); }

    return false;
}

int solve()
{
    vector<int> tree(2<<(M+1), -1);
    tree[1] = 0;

    // make a tree
    {
        vector<int> done(M, 0);

        queue<int> Q;
        Q.push(1);

        while(!Q.empty())
        {
            const int tree_index  = Q.front();
            const int metal_index = tree[tree_index];
            Q.pop();

            // disable to make a metal from the lead.
            if (R1[metal_index] == 0 || R2[metal_index] == 0) { continue; }

            // shorter path is existed!
            if (done[metal_index]) { continue; }
            done[metal_index] = 1;

            const int lhs = tree_index * 2 + 0;
            const int rhs = tree_index * 2 + 1;
            tree[lhs] = R1[metal_index];
            tree[rhs] = R2[metal_index];

            Q.push(lhs);
            Q.push(rhs);
        }
    }

    rep(i, 1024)
    {
        const bool res = merge(tree, 1);
        rep(i, M) { cout<<G[i]<<" "; } cout<<endl;

        if (!res) { break; }
    }

    return G[0];
}

int main()
{
    int t;
    cin>>t;

    rep(i, t)
    {
        cin>>M;
        rep(i, M) { cin>>R1[i]>>R2[i]; --R1[i]; --R2[i]; }
        rep(i, M) { cin>>G[i]; }

        const int ans = M > 8 ? 0 : solve();

        cout<<"Case #"<<(i+1)<<": ";
        cout<<ans<<endl;
    }

    return 0;
}
