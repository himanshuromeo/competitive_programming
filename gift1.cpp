/*
PROG: gift1
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int main(){

	freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);

	int NP,i,price,div,j;
	string name;
	map <string, pair<int,int> > m;
	cin>>NP;
	for(i=0;i<NP;i++){
		cin>>name;
		m.insert(make_pair(name,make_pair(i,0)));
	}
	/*for(map<string,int> :: const_iterator it = m.begin(); it!=m.end(); it++){
		cout<<it->first<<" "<<it->second<<"\n";
	}*/
	for(i=0;i<NP;i++){
		cin>>name>>price>>div;
		m[name].second-=price;
		if(div!=0)
			m[name].second+=price%div;
		for(j=0;j<div;j++){
			cin>>name;
			m[name].second+=price/div;
		}
	}
	for(i=0;i<NP;i++){
		for(map<string, pair<int,int> > :: const_iterator it = m.begin(); it!=m.end(); it++){
			if(it->second.first==i)
				cout<<it->first<<" "<<it->second.second<<"\n";
		}
	}
	return 0;
}