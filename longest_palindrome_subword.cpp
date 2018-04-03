//ac
//Link - http://opc.iarcs.org.in/index.php/problems/LONGPALIN
//Explanation - https://www.commonlounge.com/discussion/a13bc3bb4f04446abd032b805905a60a/all/802eca1bf24a4250af4105d58c9bc4ec 

#include<bits/stdc++.h>

using namespace std;

int main(){
	int N,i,u,v,j,count,max_count;
	bool chosen[5005];
	string A;
	cin>>N;
	cin>>A;
	max_count=0;
	for(i=0;i<N;i++){
		u=i-1;
		v=i+1;
		count=1;
		while(u>=0 && v<N){
			if(A[u]==A[v]){
				count+=2;
				u--;
				v++;
			}
			else
				break;
		}
		if(max_count<count){
			max_count=count;
			memset(chosen,0,sizeof chosen);
			for(j=u+1;j<=v-1;j++){
				chosen[j]=1;
			}
		}
	}
	for(i=0;i<N-1;i++){
		u=i;
		v=i+1;
		count=0;
		while(u>=0 && v<N){
			if(A[u]==A[v]){
				count+=2;
				u--;
				v++;
			}
			else
				break;
		}
		if(max_count<count){
			max_count=count;
			memset(chosen,0,sizeof chosen);
			for(j=u+1;j<=v-1;j++){
				chosen[j]=1;
			}
		}
	}
	cout<<max_count<<endl;
	for(i=0;i<N;i++){
		if(chosen[i])
			cout<<A[i];
	}
	cout<<endl;
	return 0;
}
