//ac

#include <bits/stdc++.h>

using namespace std;

int adj[105];
bool stmnt[105];
int put[105];
bool vis[105];

bool dfs(int v,bool parent){
  put[v]=parent;
  vis[v]=1;
  int next=adj[v];
  bool val=stmnt[v];
  if(!parent)
    val=!val;
  if(!vis[next])
    return dfs(next,val);
  else{
    if(put[next]!=val)
      return 1;
    else
      return 0;
  }
}

int main(){
  int i,T,N,x;
  bool flag,flag1,flag2;
  string s;
  while(true){
    flag=0;
    cin>>N;
    if(N==0)
      break;
    else{
      for(i=1;i<=N;i++){
        cin>>adj[i]>>s;
        if(s=="true")
          stmnt[i]=1;
        else
          stmnt[i]=0;
      }
      memset(vis,0,sizeof vis);
      for(i=1;i<=N;i++){
        if(!vis[i]){
          flag1=dfs(i,1);
          memset(vis,0,sizeof vis);
          flag2=dfs(i,0);
          if(flag1==1 && flag2==1)
            flag=1;
        }
      }
      if(flag)
        cout<<"PARADOX\n";
      else
        cout<<"NOT PARADOX\n";
    }
  }
  return 0;
}
