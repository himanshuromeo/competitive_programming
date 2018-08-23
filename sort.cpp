#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);

	int N,i,maxi,idx;
	ll x;
	vector <pair<ll,int> > A;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>x;
		A.push_back(make_pair(x,i));
	}
	maxi=-1;
	sort(A.begin(),A.end());
	for(i=0;i<N;i++){
		idx=A[i].second;
		if(idx>=i){
			maxi=max(maxi,idx-i);
		}
		//cout<<i<<" "<<idx<<" "<<maxi<<"\n";
	}
	cout<<maxi+1<<"\n";
	return 0;
}