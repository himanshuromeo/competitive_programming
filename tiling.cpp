//ac
//Link - http://opc.iarcs.org.in/index.php/problems/01TILES

#include <bits/stdc++.h>
#define MOD 10000
using namespace std;

int main(){
	int i,N;
	int A[1000005];
	cin>>N;
	A[0]=1;
	A[1]=1;
	A[2]=2;
	for(i=3;i<=N;i++){
		A[i]=(A[i-1]+A[i-2]+2*A[i-3])%MOD;
	}
	cout<<A[N]<<endl;
	return 0;
}
