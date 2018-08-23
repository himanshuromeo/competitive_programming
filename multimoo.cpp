#include <bits/stdc++.h>

using namespace std;

int N;
bool vis1[260][260];
bool vis2[260][260];
int A[260][260];

int dfs1(int i,int j){
	vis1[i][j]=1;
	int ans=0;
	if(i+1<=N && A[i+1][j]==A[i][j] && !vis1[i+1][j])
		ans+=dfs1(i+1,j);
	if(i-1>=1 && A[i-1][j]==A[i][j] && !vis1[i-1][j])
		ans+=dfs1(i-1,j);
	if(j+1<=N && A[i][j+1]==A[i][j] && !vis1[i][j+1])
		ans+=dfs1(i,j+1);
	if(j-1>=1 && A[i][j-1]==A[i][j] && !vis1[i][j-1])
		ans+=dfs1(i,j-1);
	return ans+1;
}

int dfs2(int i,int j,int val1,int val2){
	vis2[i][j]=1;
	int ans=0;
	//cout<<i<<" "<<j<<" "<<val1<<" "<<val2<<" "<<A[i][j]<<" "<<A[i+1][j]<<"\n";
	if(i+1<=N && (A[i+1][j]==val1 || A[i+1][j]==val2) && !vis2[i+1][j])
		ans+=dfs2(i+1,j,val1,val2);
	if(i-1>=1 && (A[i-1][j]==val1 || A[i-1][j]==val2) && !vis2[i-1][j])
		ans+=dfs2(i-1,j,val1,val2);
	if(j+1<=N && (A[i][j+1]==val1 || A[i][j+1]==val2) && !vis2[i][j+1])
		ans+=dfs2(i,j+1,val1,val2);
	if(j-1>=1 && (A[i][j-1]==val1 || A[i][j-1]==val2) && !vis2[i][j-1])
		ans+=dfs2(i,j-1,val1,val2);
	return ans+1;	
}

int main(){

	freopen("multimoo.in","r",stdin);
	freopen("multimoo.out","w",stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i,j;
	cin>>N;
	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++){
			cin>>A[i][j];
		}
	}
	//calculating answer for first part
	int ans1=0;
	memset(vis1,0,sizeof vis1);
	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++){
			if(!vis1[i][j])
				ans1=max(ans1,dfs1(i,j));
		}
	}
	cout<<ans1<<"\n";
	//calculating answer for second part
	memset(vis2,0,sizeof vis2);
	int ans2=0;
	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++){
			if(i>1 && !vis2[i][j]){
				ans2=max(ans2,dfs2(i,j,A[i][j],A[i-1][j]));
			}
			memset(vis2,0,sizeof vis2);
			if(i<N && !vis2[i][j]){
				ans2=max(ans2,dfs2(i,j,A[i][j],A[i+1][j]));
			}
			memset(vis2,0,sizeof vis2);
			if(j>1 && !vis2[i][j]){
				ans2=max(ans2,dfs2(i,j,A[i][j],A[i][j-1]));
			}
			memset(vis2,0,sizeof vis2);
			if(j<N && !vis2[i][j]){
				ans2=max(ans2,dfs2(i,j,A[i][j],A[i][j+1]));
			}
			memset(vis2,0,sizeof vis2);
		}
	}
	cout<<ans2<<"\n";
	return 0;
}