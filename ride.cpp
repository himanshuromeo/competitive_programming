/*
PROG: ride
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	
	freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
	
	string S1,S2;
	int val1=1,val2=1;
	cin>>S1>>S2;
	for(int i=0;i<S1.size();i++){
		val1*=(S1[i]-'A'+1);
	}
	for(int i=0;i<S2.size();i++){
		val2*=(S2[i]-'A'+1);
	}
	if(val1%47==val2%47)
		cout<<"GO\n";
	else
		cout<<"STAY\n";
	return 0;
}