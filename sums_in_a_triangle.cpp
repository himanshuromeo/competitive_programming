//source limit exceeded(>256B)
#include<bits/stdc++.h>

using namespace std;

int sums(vector<vector <int> > &A,int r,int c,int row,int dp[100][100]){
	if(dp[r][c]!=-1){
		return dp[r][c];
	}
	else if(r>=row || c>=row){
		return 0;
	}
	else{
		dp[r][c]=max(sums(A,r+1,c,row,dp),sums(A,r+1,c+1,row,dp))+A[r][c];
	}
	return dp[r][c];
}
void init_dp(int dp[100][100]){
	int i,j;
	for(i=0;i<100;i++){
		for(j=0;j<100;j++){
			dp[i][j]=-1;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,i,j,row,tmp;
	vector<vector <int> >A(100,vector<int>(100,0));
	int dp[100][100];
	cin>>n;
	while(n--){
		init_dp(dp);
		cin>>row;
		for(i=0;i<row;i++){
			for(j=0;j<i+1;j++){
				cin>>tmp;
				A[i][j]=tmp;
			}
		}
		cout<<sums(A,0,0,row,dp)<<endl;
	}	
	return 0;
}
