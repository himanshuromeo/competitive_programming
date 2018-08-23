//ac

#include<bits/stdc++.h>
#define MAXN 205
#define INF 9999999
#define NINF -999999

using namespace std;

int dp[MAXN][MAXN][MAXN];
int A[MAXN];
int N;

int solve(int idx,int i,int j){
	if(idx>N+1)
		return 0;
	else if(dp[idx][i][j]!=-1)
		return dp[idx][i][j];
	else{
		if(A[idx]>A[i] && A[idx]>=A[j])
			dp[idx][i][j]=max(solve(idx+1,idx,j)+1,solve(idx+1,i,j));
		else if(A[idx]<A[j] && A[idx]<=A[i])
			dp[idx][i][j]=max(solve(idx+1,i,idx)+1,solve(idx+1,i,j));
		else if(A[idx]<A[j] && A[idx]>A[i])
			dp[idx][i][j]=max(solve(idx+1,idx,j)+1,max(solve(idx+1,i,idx)+1,solve(idx+1,i,j)));
		else
			dp[idx][i][j]=solve(idx+1,i,j);
		return dp[idx][i][j];
	}
}

int main(){
	/*ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/
	int i,maxi,tmp;
	while(true){
		cin>>N;
		if(N==-1)
			break;
		else{
			memset(dp,-1,sizeof dp);
			A[0]=NINF;
			A[1]=INF;
			for(i=2;i<=N+1;i++){
				cin>>A[i];
			}
			cout<<N-solve(2,0,1)<<"\n";
		}
	}
	return 0;
}
