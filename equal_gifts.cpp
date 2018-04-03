//ac
//Link - http://opc.iarcs.org.in/index.php/problems/EQGIFTS
#include<bits/stdc++.h>

using namespace std;

int N;
int t_sum;
int dp[155][48050];
pair<int,int> A[155];

int min_diff(int i,int sum1){
	if(i>N)
		return abs((t_sum-sum1)-sum1);
	if(dp[i][sum1]!=-1)
		return dp[i][sum1];
	else{
		dp[i][sum1]=min(min_diff(i+1,sum1+A[i].first),min_diff(i+1,sum1+A[i].second));
		return dp[i][sum1];
	}
}

int main(){
	int i;
	memset(dp,-1,sizeof dp);
	cin>>N;
	for(i=1;i<=N;i++){
		cin>>A[i].first>>A[i].second;
		t_sum+=A[i].first+A[i].second;
	}
	cout<<min_diff(1,0)<<endl;
	return 0;
}
