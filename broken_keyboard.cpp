//ac

#include <bits/stdc++.h>

using namespace std;

int main(){
  int count[256];
  string S;
  int l,r,ans,repeat,m;
  bool flag;
  while(true){
    l=r=repeat=ans=0;
    memset(count,0,sizeof count);
    cin>>m;
    if(m==0)
      break;
    cin.ignore();
    getline(cin,S);
    while(r<S.length()){
      //cout<<S[r]<<" "<<count[(int)S[r]]<<" ";
      //cout<<l<<" "<<r;
      flag=0;
      if(count[(int)S[r]])
        repeat++;
      //cout<<" "<<repeat;
      count[(int)S[r]]++;
      if(r-l+1-repeat>m){
        if(count[(int)S[l]]>1)
          repeat--;
        count[(int)S[l]]--;
        flag=1;
      }
      if(!flag)
        ans=max(ans,r-l+1);
      //cout<<" "<<ans<<endl;
      r++;
      if(flag)
        l++;
    }
    cout<<ans<<endl;
  }
  return 0;
}
