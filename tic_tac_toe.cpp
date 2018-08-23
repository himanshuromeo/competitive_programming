//ac

#include <bits/stdc++.h>

using namespace std;

int main(){

	freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);

	string S[3];
	bool indwon[30];
	bool teamwon[30][30];
	int i,ind,grp,j;
	ind=grp=0;
	memset(indwon,0,sizeof indwon);
	memset(teamwon,0,sizeof teamwon);
	cin>>S[0]>>S[1]>>S[2];
	//row
	for(i=0;i<3;i++){
		if(S[i][0]==S[i][1] && S[i][0]==S[i][2]){
			if(!indwon[S[i][0]-'A']){
				ind++;
				indwon[S[i][0]-'A']=1;
			}
		}
		else if(S[i][0]==S[i][1]){
			if(!teamwon[S[i][0]-'A'][S[i][2]-'A']){
				grp++;
				teamwon[S[i][0]-'A'][S[i][2]-'A']=1;
				teamwon[S[i][2]-'A'][S[i][0]-'A']=1;	
			}	
		}
		else if(S[i][0]==S[i][2]){
			if(!teamwon[S[i][0]-'A'][S[i][1]-'A']){
				grp++;
				teamwon[S[i][0]-'A'][S[i][1]-'A']=1;
				teamwon[S[i][1]-'A'][S[i][0]-'A']=1;	
			}
		}
		else if(S[i][1]==S[i][2]){
			if(!teamwon[S[i][0]-'A'][S[i][1]-'A']){
				grp++;
				teamwon[S[i][0]-'A'][S[i][1]-'A']=1;
				teamwon[S[i][1]-'A'][S[i][0]-'A']=1;	
			}
		}
	}
	//column
	for(i=0;i<3;i++){
		if(S[0][i]==S[1][i] && S[0][i]==S[2][i]){
			if(!indwon[S[0][i]-'A']){
				ind++;
				indwon[S[0][i]-'A']=1;
			}
		}
		else if(S[0][i]==S[1][i]){
			if(!teamwon[S[0][i]-'A'][S[2][i]-'A']){
				grp++;
				teamwon[S[0][i]-'A'][S[2][i]-'A']=1;
				teamwon[S[2][i]-'A'][S[0][i]-'A']=1;	
			}	
		}
		else if(S[0][i]==S[2][i]){
			if(!teamwon[S[0][i]-'A'][S[1][i]-'A']){
				grp++;
				teamwon[S[0][i]-'A'][S[1][i]-'A']=1;
				teamwon[S[1][i]-'A'][S[0][i]-'A']=1;	
			}
		}
		else if(S[1][i]==S[2][i]){
			if(!teamwon[S[0][i]-'A'][S[1][i]-'A']){
				grp++;
				teamwon[S[0][i]-'A'][S[1][i]-'A']=1;
				teamwon[S[1][i]-'A'][S[0][i]-'A']=1;	
			}
		}
	}
	//left diagonal
	if(S[0][0]==S[1][1] && S[0][0]==S[2][2]){
		if(!indwon[S[0][0]-'A']){
			ind++;
			indwon[S[0][0]-'A']=1;
		}
	}
	else if(S[0][0]==S[1][1]){
		if(!teamwon[S[0][0]-'A'][S[2][2]-'A']){
			grp++;
			teamwon[S[0][0]-'A'][S[2][2]-'A']=1;
			teamwon[S[2][2]-'A'][S[0][0]-'A']=1;
		}
	}
	else if(S[0][0]==S[2][2]){
		if(!teamwon[S[0][0]-'A'][S[1][1]-'A']){
			grp++;
			teamwon[S[0][0]-'A'][S[1][1]-'A']=1;
			teamwon[S[1][1]-'A'][S[0][0]-'A']=1;
		}	
	}
	else if(S[1][1]==S[2][2]){
		if(!teamwon[S[0][0]-'A'][S[1][1]-'A']){
			grp++;
			teamwon[S[0][0]-'A'][S[1][1]-'A']=1;
			teamwon[S[1][1]-'A'][S[0][0]-'A']=1;
		}	
	}
	//right diagonal
	if(S[2][0]==S[1][1] && S[0][2]==S[2][0]){
		if(!indwon[S[0][2]-'A']){
			ind++;
			indwon[S[0][2]-'A']=1;
		}
	}
	else if(S[2][0]==S[1][1]){
		if(!teamwon[S[2][0]-'A'][S[0][2]-'A']){
			grp++;
			teamwon[S[2][0]-'A'][S[0][2]-'A']=1;
			teamwon[S[0][2]-'A'][S[2][0]-'A']=1;
		}
	}
	else if(S[0][2]==S[2][0]){
		if(!teamwon[S[0][2]-'A'][S[1][1]-'A']){
			grp++;
			teamwon[S[0][2]-'A'][S[1][1]-'A']=1;
			teamwon[S[1][1]-'A'][S[0][2]-'A']=1;
		}	
	}
	else if(S[1][1]==S[0][2]){
		if(!teamwon[S[2][0]-'A'][S[1][1]-'A']){
			grp++;
			teamwon[S[2][0]-'A'][S[1][1]-'A']=1;
			teamwon[S[1][1]-'A'][S[2][0]-'A']=1;
		}	
	}
	cout<<ind<<"\n"<<grp<<"\n";
	return 0;
}