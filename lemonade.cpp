#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

	freopen("lemonade.in","r",stdin);
	freopen("lemonade.out","w",stdout);
 
	int N,i,place,posopt;
	int cnt=0;
	ll wt[100005];
	cin>>N;
	for(i=0;i<N;i++){
		cin>>wt[i];
	}
	sort(wt,wt+N);
	for(i=N-1;i>=0;i--){
		if(wt[i]<cnt)
			break;
		cnt++;
	}
	cout<<cnt<<"\n";
	return 0;
}