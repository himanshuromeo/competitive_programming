//ac

#include <bits/stdc++.h>
#define INF 99999999

using namespace std;

int t,s,l,i,j,N,P,Q,T,x;
int dist[160][160];
int order[160],K[6010],lq[6010],rq[6010],ans[6010];

int main(){

	freopen("road_network.in","r",stdin);
	freopen("road_network.out","w",stdout);

	cin>>T;
	for(t=1;t<=T;t++){
		cin>>N;
		for(i=1;i<=N;i++){
			for(j=1;j<=N;j++){
				dist[i][j]=INF;
			}
		}
		for(i=1;i<=N;i++){
			dist[i][i]=0;
			for(j=i+1;j<=N;j++){
				cin>>x;
				if(x!=-1)
					dist[j][i]=dist[i][j]=x;
			}
		}
		cin>>P;
		for(i=1;i<=P;i++){
			cin>>order[i];
		}
		cin>>Q;
		for(i=1;i<=Q;i++){
			cin>>K[i]>>lq[i]>>rq[i];
		}
		//floyd-warshall
		for(i=1;i<=Q;i++){
			if(K[i]==0)
				ans[i]=dist[lq[i]][rq[i]];
		}
		for(l=1;l<=P;l++){
			s=order[l];
			for(i=1;i<=N;i++){
				for(j=1;j<=N;j++){
					dist[i][j]=min(dist[i][j],dist[i][s]+dist[s][j]);
				}
			}
			for(i=1;i<=Q;i++){
				if(K[i]==l){
					ans[i]=dist[lq[i]][rq[i]];
				}
			}
		}
		cout<<"Case "<<t<<": ";
		for(i=1;i<=Q;i++){
			if(ans[i]>=INF)
				cout<<-1<<" ";
			else
				cout<<ans[i]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}