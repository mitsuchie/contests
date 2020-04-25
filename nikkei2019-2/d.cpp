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

#define REP(i,p,n) for(ll i=p;i<ll(n);++i)
#define rep(i,n) REP(i,0,n)

using ll = long long int;
using pll = pair<ll, ll>;

const ll MOD = static_cast<ll>(1e9) + 7;
const ll INF = 100000000000LL;

struct SegmentTree
{
  using u32 = unsigned int;
  u32 msb(u32 x) { u32 l=0, r=32, m=0; while (l+1<r){ m=(l+r)>>1; (x>>m?l:r)=m; } return l; }

  vector<ll> data;

  // 親子関係 => 親:(p-1)/2, 左:p*2+1, 右:p*2+2
  void init(ll n, ll v=0)
  {
      data.assign((1 << (msb(n - 1) + 1)) * 2 - 1, v);
  }

  // ノード数
  inline int size() const
  {
      return (data.size() + 1) >> 1;
  }

  // 葉から木全体の値を更新する
  void update(ll p, ll x)
  {
      p += size() - 1;
      cout << "data[" << p << "] == " << data[p] << " <= " << x << endl;
      data[p] = min(data[p], x);

      while (p > 0)
      {
          p = (p - 1) >> 1;
          cout << "data[" << p << "] == " << data[p] << " <= " << x << endl;
          data[p] = min(data[p], x);
      }
  }

  // 二分木の構造を利用して区間の値を取得する
  ll query(ll a, ll b)
  {
      return query(a, b, 0, 0, size() - 1);
  }

  ll query(ll a, ll b, ll k, ll l, ll r)
  {
      cout << "a=" << a << ", b=" << b << ", k=" << k << ", l=" << l << ", r=" << r << endl;
      if(r <= a || b <= l) { cout << "outer=" << INF << endl; return INF; }
      if(a <= l && r <= b) { cout << "data[" << k << "]=" << data[k] << endl; return data[k]; }

      const auto lhs = query(a, b, (k << 1) + 1, l, ((l + r) >> 1));
      const auto rhs = query(a, b, (k << 1) + 2, (l + r) >> 1, r);
      const auto res = min(lhs, rhs);

      cout << "res=" << res << endl;
      return res;
  }

} segtree;

struct Node
{
    ll lhs, rhs, cost;

    bool operator<(const auto& x)
    {
        return lhs < x.lhs;
    }
};

int main()
{
    ll N, M;
    cin >> N >> M;

    segtree.init(N + 1, INF);

    vector<Node> nodes(M);
    for (auto&& node : nodes)
    {
        cin >> node.lhs >> node.rhs >> node.cost;
        --node.lhs;
        --node.rhs;
    }

    sort(nodes.begin(), nodes.end());

    segtree.update(0, 0);

    ll ans = INF;

    for (const auto& node : nodes)
    {
        cout << endl;
        const auto prevCost = segtree.query(node.lhs, node.rhs);
        cout << "lhs=" << node.lhs << ", rhs=" << node.rhs << ", cost=" << node.cost << endl;
        cout << "| prevCost=" << prevCost << endl;

        if (prevCost == INF) { continue; }

        const auto nextCost = prevCost + node.cost;

        cout << "| nextCost=" << nextCost << endl;

        segtree.update(node.rhs, nextCost);

        ans = nextCost;
    }

    cout << (ans == INF ? -1 : ans) << endl;

    return 0;
}
