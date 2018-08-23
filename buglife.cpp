//ac

#include <bits/stdc++.h>
#define pb push_back

using namespace std;

vector <int> adj[1000005];
int color[1000005];
bool vis[1000005];
int V,E;
bool bipartite;

void process_edge(int a,int b){
  if(color[a]==color[b])
    bipartite=0;
  else
    color[b]=!color[a];
}

void bfs(int u){
  queue<int> Q;
  Q.push(u);
  vis[u]=1;
  while(!Q.empty()){
    int v=Q.front();
    Q.pop();
    for(int i=0;i<adj[v].size();i++){
      if(!vis[adj[v][i]]){
        Q.push(adj[v][i]);
        vis[adj[v][i]]=1;
      }
      process_edge(v,adj[v][i]);
    }
  }
}

int main(){
  int T,i,a,b;
  cin>>T;
  for(int j=1;j<=T;j++){
    cin>>V>>E;
    for(i=0;i<E;i++){
      cin>>a>>b;
      adj[a].pb(b);
      adj[b].pb(a);
    }
    memset(vis,0,sizeof vis);
    memset(color,-1,sizeof color);
    bipartite=1;
    for(i=1;i<=V;i++){
      if(!vis[i]){
        color[i]=0;
        bfs(i);
      }
    }
    cout<<"Scenario #"<<j<<":\n";
    if(bipartite)
      cout<<"No suspicious bugs found!\n";
    else
      cout<<"Suspicious bugs found!\n";
    for(i=1;i<=V;i++){
      adj[i].clear();
    }
  }
  return 0;
}
