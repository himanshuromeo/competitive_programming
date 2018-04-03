//ac
//Link - https://orac.amt.edu.au/cgi-bin/train/problem.pl?set=aio16sen&problemid=906

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ofstream fout("balanceout.txt");
ifstream fin("balancein.txt");

int main(){
  int S,i,left_idx,right_idx,moves=0;
  ll stack[100005];
  fin>>S;
  for(i=0;i<S;i++){
    fin>>stack[i];
  }
  left_idx=0;
  right_idx=S-1;
  while(left_idx<right_idx){
    if(stack[left_idx]>stack[right_idx]){
      right_idx --;
      stack[right_idx]+=stack[right_idx+1];
      moves ++;
    }
    else if(stack[left_idx]<stack[right_idx]){
      left_idx ++;
      stack[left_idx]+=stack[left_idx-1];
      moves ++;
    }
    else{
      left_idx ++;
      right_idx --;
    }
  }
  fout<<moves<<endl;
  return 0;
}
