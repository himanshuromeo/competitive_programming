//ac
//Link - http://opc.iarcs.org.in/index.php/problems/ENDCORR

#include <bits/stdc++.h>

using namespace std;

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	int i,M,N,tmp;
	priority_queue<int> Q;
	cin>>N>>M;
	for(i=0;i<M+N;i++){
		cin>>tmp;
		if(tmp==-1){
			cout<<Q.top()<<"\n";
			Q.pop();
		}
		else
			Q.push(tmp);
	}
	return 0;
}
