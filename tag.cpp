//ac
//Link - https://orac.amt.edu.au/cgi-bin/train/problem.pl?set=aio17int&problemid=980
#include <bits/stdc++.h>

using namespace std;

ofstream fout("tagout.txt");
ifstream fin("tagin.txt");

int main(){
  bool team[100005];
  int N,M,a,b,t1=1,t2=1,i;
  team[1]=0;
  team[2]=1;
  fin>>N>>M;
  for(i=0;i<M;i++){
    fin>>a>>b;
    team[b]=team[a];
    if(team[b]==0)
      t1++;
    else
      t2++;
  }
  fout<<t1<<" "<<t2<<endl;
  return 0;
}
