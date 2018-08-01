#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;


// rmq question
// 在线算法 ST O(nlogn)预处理 O(1) 查询
const int maxi=100+1,maxj=10;
int a[maxi];
int dp[maxi][maxj]; // dp[i][j] 表示i-i+2^j-1的rmq问题
void init(int n) {
	for(int i=1;i<=n;++i)
		dp[i][0]=a[i];
	for(int j=1;j<ceil(log(n));++j){
		for(int i=1;i<=n;++i){
			if(i+pow(2,j)-1<=n){
				dp[i][j]=max(dp[i][j-1],dp[i+pow(2,j-1)][j-1]);
			}
		}
	}
}

int query(int l,int r) {
	int k = floor(log(r-l+1)); // prove true
	return max(dp[l][k],dp[j-pow(2,k)+1][k]);
}
// lca question
// 对于一次查询 O(n)
// tarjan O(n+Q) 离线算法
const int maxn=1000;
int ancsetor[maxn];
bool checked[maxn];
node nodes[maxn];
void lca(int u) {
	ancsetor[u] = u;
	checked[u] = true;
	for(v in u.childs()){ // 遍历u的每一个孩子
		lca(v);
		ancsetor[v] = u;
		_union(u,v);
	}
	if(pair<int,int>(u,v) in query){ // 遍历所有query u,v
		if(checked[v])
			ans=ancsetor(v);
	}
}
