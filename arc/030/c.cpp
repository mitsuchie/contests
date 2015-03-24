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
#include <bitset>
using namespace std;

#define REP(i,p,n) for(int i=p;i<n;++i)
#define rep(i,n) REP(i,0,n)

typedef long long int ll;
typedef complex<double> point;
typedef pair<int,int> pii;
typedef vector<int> vint;
typedef vector<pii> vpii;
typedef pair<int,int> pii;
typedef vector<vint> det1;
typedef vector<vpii> det2;
const int MAXN = 300;
const int MAXM = 1000;
const int MAXK = 300;
int N,M,K;
vector<char> CS;
det1 G,R;

struct StringConnectedComponent // 強連結成分分解
{
	typedef vector<vector<int> > list;
	vector<int> mGids, mOrders;

	int init(const list& g,const list& r)
	{
		int gid = 0;

		mGids.assign(g.size(),-1);
		rep(i,g.size()){ if(mGids[i]==-1){ dfs(i,0,g,0); } }
		rep(i,g.size()){ mGids[i] = -1; }

		reverse(mOrders.begin(),mOrders.end());
		rep(i,mOrders.size()){ if(mGids[mOrders[i]]==-1){ dfs(mOrders[i],gid++,r,1); } }

		return gid;
	}

	void dfs(int p,int gid,const list& g,int rev)
	{
		mGids[p] = gid;

		rep(i,g[p].size()){ if(mGids[g[p][i]]==-1){ dfs(g[p][i],gid,g,rev); } }
		if(!rev){ mOrders.push_back(p); }
	}

	void makeGraph(list& dst,const list& src)
	{
		dst.assign(src.size(),vector<int>());
		rep(i,src.size()) rep(j,src[i].size()) if(mGids[i]!=mGids[src[i][j]])
		{
			vector<int>& r = dst[mGids[i]];
			if(count(r.begin(),r.end(),mGids[src[i][j]])==0){ r.push_back(mGids[src[i][j]]); }
		}
	}

} scc;

string dp[MAXN][MAXK];

int main()
{
	// 入力処理
	cin>>N>>M>>K;
	CS.assign(N,0);
	rep(i,N){ cin>>CS[i]; }

	// グラフ作成
	G.assign(N,vint());
	R.assign(N,vint());

	int a, b;
	rep(i,M)
	{
		cin>>a>>b;
		--a;
		--b;
		
		G[a].push_back(b);
		R[b].push_back(a);
	}

	// 強連結成分分解
	int sccn = scc.init(G,R);
	cout<<sccn<<endl;

	vector<vector<int> > graph;
	scc.makeGraph(graph,G);

	vector<string> strs(scc.size());
	rep(i,N){ strs[scc.mGids[i]] += CS[i]; }
	rep(i,sccn){ sort(strs[i].begin(),strs[i].end()); }

	vector<int> used(sccn,0);
	rep(i,N)
	{
		int gid = scc.mGids[scc.mOrders[i]]; // 該当の強連結成分
		if(used[gid]){ continue; } else { used[gid]=1; }

		rep(j,K) // 既に選択した文字数
		{
			rep(k,min(K+1-j,strs[gid].size())) // 何文字とるか
			{
				string s = dp[gid][k+j]
				rep(t,graph[gid].size())
				{
					dp[gid][k+j] = min(dp[gid][k+j],
				}
			}
		}


	}
/*
	// DP準備
	string ng;
	ng += ('z'+1);

	rep(i,N){ rep(j,K){ dp[i][j] = ng; } }
	rep(i,N){ dp[i][0] = ""; }

	// DP開始
	rep(i,scc.size())
	{
		const int limit = min((int)strs[i].size(),K);

		for(int j=K;j>=0;--j) rep(k,limit) if(j+k+1<=K)
		{
			string next = dp[i][j] + strs[i].substr(0,k+1);
			if(
		}
	}

	// rep(i,N){ cout<<i<<": is_root? #=> "<<scc.isRoot(i)<<endl; }
*/
	return 0;
}
