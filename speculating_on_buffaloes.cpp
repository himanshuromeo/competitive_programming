//ac

#include<bits/stdc++.h>
#define MINV -1000000000
using namespace std;
typedef long long ll;

ll A[405];
ll dp[405][405][2];
bool vis[405][405][2];
int N;

ll max_profit(int i,int k,bool state){
	if(k<0)
		return MINV;
	if(i>N)
		return 0;
	if(vis[i][k][state])
		return dp[i][k][state];
	else{
		vis[i][k][state]=1;
		if(state==1){
			dp[i][k][state]=max(max_profit(i+1,k,state),max_profit(i+1,k-1,0)+A[i]);
		}
		else{
			dp[i][k][state]=max(max_profit(i+1,k,state),max_profit(i+1,k-1,1)-A[i]);
		}
		return dp[i][k][state];
	}
}

int main(){
	int i,K;
	memset(vis,0,sizeof vis);
	cin>>N>>K;
	for(i=1;i<=N;i++){
		cin>>A[i];
	}
	cout<<max_profit(1,K,0)<<endl;
	return 0;
}