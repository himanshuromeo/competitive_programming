//ac

#include <bits/stdc++.h>

using namespace std;

ofstream fout("cocoout.txt");
ifstream fin("cocoin.txt");

int main(){
  long long Ix,Iy,Id,Cx,Cy,Cd;
  fin>>Ix>>Iy>>Id;
  fin>>Cx>>Cy>>Cd;
  if((Id+Cd)*(Id+Cd)>=(Ix-Cx)*(Ix-Cx)+(Iy-Cy)*(Iy-Cy) && (Id-Cd)*(Id-Cd)<=(Ix-Cx)*(Ix-Cx)+(Iy-Cy)*(Iy-Cy))
    fout<<"yes"<<endl;
  else
    fout<<"no"<<endl;
  return 0;
}
