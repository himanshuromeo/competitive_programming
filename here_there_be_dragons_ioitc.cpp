//ac

#include <bits/stdc++.h>
#define INF 1000000000005

using namespace std;

int K,D;
long long R,C;
vector <pair <long long,long long> >A;
unsigned long long dp[305][305][305];

unsigned long long minsteps(int K,int last,int now){
  if(K==0)
    return 0;
  if(now>D)
    return INF;
  if(dp[K][last][now]!=-1)
    return dp[K][last][now];
  else{
    dp[K][last][now]=min(minsteps(K-1,now,now+1)+abs(A[now].first-A[last].first)+abs(A[now].second-A[last].second),minsteps(K,last,now+1));
    return dp[K][last][now];
  }
}

int main(){
  int i;
  long long a,b;
  memset(dp,-1,sizeof dp);
  cin>>R>>C>>K>>D;
  A.push_back(make_pair(0,0));
  for(i=0;i<D;i++){
    cin>>a>>b;
    A.push_back(make_pair(a,b));
  }
  sort(A.begin(),A.end());
  cout<<minsteps(K,0,1)<<endl;
}
