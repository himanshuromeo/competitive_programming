//ac
//Link - https://orac.amt.edu.au/cgi-bin/train/problem.pl?set=aio17int&problemid=973
#include <bits/stdc++.h>

using namespace std;

ofstream fout("manout.txt");
ifstream fin("manin.txt");

int main(){
  int Ix,Cx,Id,Cd;
  fin>>Ix>>Cx>>Id>>Cd;
  if(Ix-Id==Cx-Cd)
    fout<<Ix-Id;
  else if(Ix+Id==Cx+Cd)
    fout<<Ix+Id;
  else if(Ix-Id==Cx+Cd)
    fout<<Ix-Id;
  else if(Ix+Id==Cx-Cd)
    fout<<Ix+Id;
  fout<<endl;
  return 0;
}
