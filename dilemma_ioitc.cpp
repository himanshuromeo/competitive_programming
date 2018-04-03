//ac

#include <bits/stdc++.h>

using namespace std;

int M,N;
int A[1505][1505];
pair <int,int> next[1505][1505][5];
int dp[1505][1505];

int maxvisit(int i,int j){
  if(i>M || j>N || i<1 ||j<1)
    return 0;
  if(dp[i][j]!=-1)
    return dp[i][j];
  int a=maxvisit(next[i][j][1].first,next[i][j][1].second);
  int b=maxvisit(next[i][j][2].first,next[i][j][2].second);
  int c=maxvisit(next[i][j][3].first,next[i][j][3].second);
  int d=maxvisit(next[i][j][4].first,next[i][j][4].second);
  dp[i][j] = max(max(a,b),max(c,d))+1;
  return dp[i][j];
}

int main(){
  int i,j,now,maxi;
  cin>>M>>N;
  for(i=1;i<=M;i++){
    for(j=1;j<=N;j++){
      cin>>A[i][j];
    }
  }
  memset(dp,-1,sizeof dp);
  //(1)--->
  for(i=1;i<=M;i++){
    next[i][N][1].first=i;
    next[i][N][1].second=N+1;
    for(j=N-1;j>=1;j--){
      now=j+1;
      while(now<=N){
        if(A[i][j]>A[i][now]){
          next[i][j][1].first=i;
          next[i][j][1].second=now;
          break;
        }
        else
          now=next[i][now][1].second;
      }
      if(now>N){
        next[i][j][1].first=i;
        next[i][j][1].second=N+1;
      }
      //cout<<"("<<i<<","<<j<<") - "<<next[i][j][1].first<<" "<<next[i][j][1].second<<endl;
    }
  }
  //<---(2)
  for(i=1;i<=M;i++){
    next[i][1][2].first=i;
    next[i][1][2].second=0;
    for(j=2;j<=N;j++){
      now=j-1;
      while(now>=1){
        if(A[i][j]>A[i][now]){
          next[i][j][2].first=i;
          next[i][j][2].second=now;
          break;
        }
        else
          now=next[i][now][2].second;
      }
      if(now<1){
        next[i][j][2].first=i;
        next[i][j][2].second=0;
      }
      //cout<<"("<<i<<","<<j<<") - "<<next[i][j][2].first<<" "<<next[i][j][2].second<<endl;
    }
  }
  // down (3)
  for(j=1;j<=N;j++){
    next[M][j][3].first=M+1;
    next[M][j][3].second=j;
    for(i=M-1;i>=1;i--){
      now=i+1;
      while(now<=M){
        if(A[i][j]>A[now][j]){
          next[i][j][3].first=now;
          next[i][j][3].second=j;
          break;
        }
        else
          now=next[now][j][3].first;
      }
      if(now>M){
        next[i][j][3].first=M+1;
        next[i][j][3].second=j;
      }
      //cout<<"("<<i<<","<<j<<") - "<<next[i][j][3].first<<" "<<next[i][j][3].second<<endl;
    }
  }
  // up (4)
  for(j=1;j<=N;j++){
    next[1][j][4].first=0;
    next[1][j][4].second=j;
    for(i=2;i<=M;i++){
      now=i-1;
      while(now>=1){
        if(A[i][j]>A[now][j]){
          next[i][j][4].first=now;
          next[i][j][4].second=j;
          break;
        }
        else
          now=next[now][j][4].first;
      }
      if(now<1){
        next[i][j][4].first=0;
        next[i][j][4].second=j;
      }
      //cout<<"("<<i<<","<<j<<") - "<<next[i][j][4].first<<" "<<next[i][j][4].second<<endl;
    }
  }
  for(i=1;i<=M;i++){
    for(j=1;j<=N;j++){
      maxi=max(maxi,maxvisit(i,j));
    }
  }
  cout<<maxi<<endl;
  return 0;
}
